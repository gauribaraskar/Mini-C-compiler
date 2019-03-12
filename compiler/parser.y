/* The file describes the grammar for our parser */
%{
    // Header files
    #include<stdio.h>
	  #include<stdlib.h>
	  #include "tables.h"
    #include<limits.h>
    #include<ctype.h>
    #include<string.h>

    // Initialising Symbol table and constant table
    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;
    
    int yyerror(char *msg);
    int checkScope(char *value);
    int typeCheck(char*,char*,char*);
    int checkFunc(char*);
    char* curr_data_type;
    int yylex(void);
    int is_bool = 1;
    int curr_nest_level = 1;
    int arrayDim;

    extern int yylineno;
    extern char* yytext;

    
    int is_declaration = 0;
    int is_function = 0;
    char* func_type;
    char *param_list[10];
     char *arg_list[10];
   
    int p_idx = 0;
    int a_idx = 0;
    int p=0;
    char *param_list[10];
    char *arg_list[10];

   char *expr_type;
   char *mut_type;
    

%}

// Data types of tokens
%union{
  	char *str;
  	entry *tbEntry;
  	double dval;
}

/* Operators */
%token ADD SUBTRACT MULTIPLY DIVIDE ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN  MOD
/* Relational Operators */
%token GREATER_THAN LESSER_THAN LESS_EQ GREATER_EQ NOT_EQ EQUAL
/* Keywords */
%token VOID IF ELSE FOR DO WHILE GOTO BREAK CONTINUE RETURN
/* Data types */
%token INT SHORT LONG CHAR FLOAT
/* Logical Operators */
%token LG_OR LG_AND NOT
/* Assignment Operators */
%token DECREMENT INCREMENT
/* Constants */
%token <tbEntry> HEX_CONSTANT DEC_CONSTANT INT_CONSTANT
/* String */
%token <str> STRING
/* Identifier */
%token <tbEntry> IDENTIFIER 


 %type <tbEntry> identifier varDecId
 %type <str> mutable call factor expression simpleExpression andExpression sumExpression unaryExpression unaryRelExpression term immutable relExpression const_type


// Start Symbol of the grammar
%start program

/* Precedence of Operators */
%left ','
%right ASSIGN
%left LG_OR
%left LG_AND
%left EQUAL NOT_EQ
%left LESSER_THAN GREATER_THAN LESS_EQ GREATER_EQ
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MOD
%right NOT


%nonassoc IFX
%nonassoc ELSE
%%
   
    program : declarationList;
   
    declarationList : declarationList declaration | declaration;
   
    declaration : varDeclaration | funDeclaration ;
   
    varDeclaration : typeSpecifier varDeclList ';' {is_declaration = 0;} ;
    
    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;
    
    varDeclInitialize : varDecId | varDecId ASSIGN simpleExpression {typeCheck($1->data_type,$3,"=");} ;
    varDecId : identifier {$$=$1;} | identifier '[' INT_CONSTANT  ']' { if($3->value < 1){yyerror("Arrays can't have dimension lesser than 1");} $$=$1; $1->is_array = 1; $1->array_dim = (int)$3->value;};
    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");  is_declaration = 1; }
                  | VOID {curr_data_type = strdup("VOID");  is_declaration = 1; }
                  | CHAR {curr_data_type = strdup("CHAR");  is_declaration = 1;}
		  | FLOAT {curr_data_type = strdup("FLOAT");  is_declaration = 1;}
                  ;

    
    
    pointer : MULTIPLY pointer | MULTIPLY;

    
    funDeclaration : typeSpecifier 
                     identifier             {
                                                
                                                func_type = curr_data_type;
						is_declaration = 0;

                                            }
                     '(' params ')'         {
                                               fill_parameter_list($2,param_list,p_idx);
                                                p_idx = 0;
                                                is_function = 1;
						int flag = set_is_function(SymbolTable,$2->lexeme);
                        if(flag == 0){return -1;}
                                                p=1;
                                            }  
                     compoundStmt           { is_function = 0;
					     };

     // Rules for parameter list
    params : paramList | ;
    paramList : paramList ',' paramTypeList | paramTypeList;
    paramTypeList : typeSpecifier

                      paramId   {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                             
                                };
    paramId : identifier | identifier '[' ']';  
    // Types os statements in C
    statement : expressionStmt  | compoundStmt  | selectionStmt | iterationStmt | jumpStmt | returnStmt | breakStmt | varDeclaration ;

    // compound statements produces a list of statements with its local declarations
    compoundStmt : {curr_nest_level++;}'{' statementList '}' {insertNest(curr_nest_level,yylineno);};
    statementList : statementList statement
                  |  ;
    // Expressions
    expressionStmt : expression ';' | ';' ;
    selectionStmt : IF '(' simpleExpression ')' statement %prec IFX
                  | IF '(' simpleExpression ')' statement ELSE statement
                  ;

    iterationStmt : WHILE '(' simpleExpression ')' statement
                  | DO statement WHILE '(' expression ')' ';'
                  | FOR '(' optExpression ';' optExpression ';' optExpression ')' statement;
    // Optional expressions in case of for
    optExpression : expression | ;

    jumpStmt : GOTO identifier ';' | CONTINUE ';' ;
    returnStmt : RETURN ';'  { if(is_function) { if(strcmp(func_type,"VOID")!=0) yyerror("return type (VOID) does not match function type");}}

               | RETURN expression {
                                      if(strcmp(curr_data_type,$2)!=0)
                                        yyerror("return type does not match function type");
                                   } ;
    breakStmt : BREAK ';' ;

    expression : mutable ASSIGN expression {typeCheck($1,$3,"=");$$ = $1;}
               | mutable ADD_ASSIGN expression {typeCheck($1,$3,"+=");$$ = $1;}
               | mutable SUB_ASSIGN expression {typeCheck($1,$3,"-=");$$ = $1;}
               | mutable MUL_ASSIGN expression {typeCheck($1,$3,"*=");$$ = $1;}
               | mutable DIV_ASSIGN expression {typeCheck($1,$3,"/=");$$ = $1;}
               | mutable INCREMENT { $$ = $1;}
               | mutable DECREMENT { $$ = $1;}
               | simpleExpression { $$ = $1;} 
               ;

    simpleExpression : simpleExpression LG_OR andExpression { $$ = $1;} 
                     | andExpression { $$ = $1;};

    andExpression : andExpression LG_AND unaryRelExpression { $$ = $1;} 
                  | unaryRelExpression { $$ = $1;} ;

    unaryRelExpression : NOT unaryRelExpression { $$ = $2;}
                       | relExpression { $$ = $1;} ;

    relExpression : sumExpression GREATER_THAN sumExpression {typeCheck($1,$3,">");$$ = $1;}
                  | sumExpression LESSER_THAN sumExpression {typeCheck($1,$3,"<");$$ = $1;} 
                  | sumExpression LESS_EQ sumExpression {typeCheck($1,$3,"<=");$$ = $1;}
                  | sumExpression GREATER_EQ sumExpression {typeCheck($1,$3,">=");$$ = $1;}
                  | sumExpression NOT_EQ sumExpression {typeCheck($1,$3,"!=");$$ = $1;}
                  | sumExpression EQUAL sumExpression {typeCheck($1,$3,"==");$$ = $1;}
                  | sumExpression { $$ = $1;}
                  ;
    sumExpression : sumExpression ADD term {typeCheck($1,$3,"+");$$ = $1;}
                  | sumExpression SUBTRACT term {typeCheck($1,$3,"-");$$ = $1;}
                  | term { $$ = $1;}
                  ;

   

    term : term MULTIPLY unaryExpression {typeCheck($1,$3,"*");$$ = $1;}
         | term DIVIDE unaryExpression {typeCheck($1,$3,"/");$$ = $1;}
         | unaryExpression { $$ = $1;}
         ;

    unaryExpression : ADD unaryExpression { $$ = $2;}
                    | SUBTRACT unaryExpression { $$ = $2;}
                    | factor { $$ = $1;} ;


    factor : immutable {$$ = $1;} | mutable {$$ = $1;};
    mutable : identifier {checkScope(yylval.str); $$ = $1->data_type;}| identifier '[' INT_CONSTANT ']' {if($3->value < 0 || $3->value >= $1->array_dim ){yyerror("Exceeds Array Dimensions\n"); } $$ = "";}
    immutable : '(' expression ')' { $$ = $2;}| call {$$=$1;} | const_type {$$=$1;} ;
    call : identifier '(' args ')' { 
                                      if(checkFunc($1->lexeme) == 0)
                                        {return -1;};
                                      $$ = $1->data_type;
                                      check_parameter_list($1,arg_list,a_idx);
                                      a_idx = 0;
                                    }
    args : argList | ;
  
    argList : argList ',' arg
	    | arg ;

    arg : expression     {
                            arg_list[a_idx] = (char *)malloc(sizeof($1));
                            strcpy(arg_list[a_idx++],$1);
                        }
          ;

    const_type : DEC_CONSTANT { $$ = $1->data_type;}
               | INT_CONSTANT { $$ = $1->data_type;}
               | HEX_CONSTANT { $$ = $1->data_type;}
               | STRING       
               ;
    identifier : IDENTIFIER { 
					if(is_declaration){
					// $1 = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
					$$ = $1;
                    is_function = 0;
					}
					else 
					{
					$1 = Search(SymbolTable,yytext);
					$$ = $1;
                    if($1 == NULL)
                    {
                        yyerror("Variable Not Declared");
                        return -1;
                    }
					}
			    };
%%


int checkFunc(char* lexeme)
{
    entry *res = searchFunc(SymbolTable,lexeme);
    if(res != NULL)
    {
        res = InsertSearch(SymbolTable,lexeme,curr_nest_level);
        if(res != NULL)
        {
            yyerror("Defined as variable in this scope, calling not allowed");
            return 0;
        }
        else
        {
            return 1;
        }
        
    }
    else
    {
        yyerror("No such declaration\n");
        return 0;
    }
}

int typeCheck(char *a,char *b,char *c){
	
	if(strcmp(a,b)!=0){
		yyerror("Type Mismatch");
		exit(0);
	}

	else 
		return 1;
}
void disp()
{
    printf("\n\tSymbol table");
    Display(SymbolTable);
    printf("\n\tConstant table");
    Display(ConstantTable);
}

int checkScope(char *val)
{
    char *extract = (char *)malloc(sizeof(char)*32);
    int i;
    // Don't touch this CRUCIAL AS FUCK
    for(i = 0; i < strlen(val) ;i=i+1)
    {
        //printf("%d\n",i);
        if((isalnum(*(val + i)) != 0) || (*(val + i)) == '_')
        {
            *(extract + i) = *(val + i);
        }
        else
        {
            *(extract + i) = '\0';
            break;
        }
    }
    
    entry *res = Search(SymbolTable,extract);
    // First check if variable exists then check for nesting level
    if (res == NULL)
    {
        yyerror("Variable Not Declared\n");
        return 0;
    }
    else
    { 
        int level = res->nesting_level;
        int endLine = -1;
        if(Nester[level] == NULL)
            endLine = yylineno + 100;
        else
            endLine = Nester[level]->line_end;
        if(level <= curr_nest_level && yylineno <= endLine)
        {
            
            return 1;
        }
        else
        {
            
            yyerror("Variable Out Of Scope\n");
            return 0;
        }
    }
    
}

#include "lex.yy.c"
int main(int argc , char *argv[]){

    SymbolTable = CreateTable();
    ConstantTable = CreateTable();
    nested_homekeeping();
    int i;
    // Open a file for parsing
    yyin = fopen(argv[1], "r");

    if(!yyparse())
    {
        printf("\nParsing complete.\n");
        disp();
    }
    else
    {
            printf("\nParsing failed.\n");
    }

    fclose(yyin);
    return 0;
}

int yyerror(char *msg)
{
  // Function to display error messages with line no and token
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}


