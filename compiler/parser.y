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
    void type_check(int,int,int);
    char* curr_data_type;
    int yylex(void);
    int is_bool = 1;
    int curr_nest_level = 1;

    extern int yylineno;
    extern char* yytext;

    
    int is_func = 0;
    char* func_type;
    char *param_list[10];
     char *arg_list[10];
   
    int p_idx = 0;
    int p=0;
    char *param_list[10];
    

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
%token INT SHORT LONG CHAR
/* Logical Operators */
%token LG_OR LG_AND NOT
/* Assignment Operators */
%token DECREMENT INCREMENT
/* Constants */
%token <dval> HEX_CONSTANT DEC_CONSTANT INT_CONSTANT
/* String */
%token <str> STRING
/* Identifier */
%token <tbEntry> IDENTIFIER 

%type <dval> expression unaryExpression unaryRelExpression simpleExpression andExpression
 sumExpression relExpression term factor mutable immutable call
 %type <dval> const_type

 %type <tbEntry> identifier 


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
   
    varDeclaration : typeSpecifier varDeclList ';' ;
    
    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;
    
    varDeclInitialize : varDecId | varDecId ASSIGN simpleExpression ;
    varDecId : identifier | identifier '[' INT_CONSTANT ']';
    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");}
                  | VOID {curr_data_type = strdup("VOID");}
                  | CHAR {curr_data_type = strdup("CHAR");}
                  ;

    
    
    pointer : MULTIPLY pointer | MULTIPLY;

    
    funDeclaration : typeSpecifier 
                     identifier             {
                                                
                                                func_type = curr_data_type;
                                            }
                     '(' params ')'         {
                                               fill_parameter_list($2,param_list,p_idx);
                                                p_idx = 0;
                                                is_func = 1;
                                                p=1;
                                            }  
                     compoundStmt           { is_func = 0;};

     // Rules for parameter list
    params : paramList | ;
    paramList : paramList ',' paramTypeList | paramTypeList;
    paramTypeList : typeSpecifier

                      paramId   {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                             
                                };
    paramId : IDENTIFIER | IDENTIFIER '[' ']';  
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

    jumpStmt : GOTO IDENTIFIER ';' | CONTINUE ';' ;
    returnStmt : RETURN ';'
               | RETURN expression ;
    breakStmt : BREAK ';' ;

    expression : mutable ASSIGN expression {type_check($1,$3,0);$1 = $3;}
               | mutable ADD_ASSIGN expression {$1 = $1+$3;}
               | mutable SUB_ASSIGN expression  { $1 = $1-$3;}
               | mutable MUL_ASSIGN expression { $1 = $1*$3;}
               | mutable DIV_ASSIGN expression {$1 = $1/ $3;}
               | mutable INCREMENT { $1 = $1+1;}
               | mutable DECREMENT {  $1 = $1-1;}
               | simpleExpression  {$$=$1;}
               ;

    simpleExpression : simpleExpression LG_OR andExpression {$$ = $1 || $3;}
                     | andExpression{$$=$1;};

    andExpression : andExpression LG_AND unaryRelExpression {$$ = $1 && $3;}
                  | unaryRelExpression {$$=$1;};

    unaryRelExpression : NOT unaryRelExpression {$$ = (!$2);}
                       | relExpression {$$=$1;} ;

    relExpression : sumExpression GREATER_THAN sumExpression {$$ = ($1 > $3); printf("%f",$$);}
                  | sumExpression LESSER_THAN sumExpression  {$$ = ($1 < $3);}
                  | sumExpression LESS_EQ sumExpression  {$$ = ($1 <= $3);}
                  | sumExpression GREATER_EQ sumExpression {$$ = ($1 >= $3);}
                  | sumExpression NOT_EQ sumExpression {$$ = ($1 != $3);}
                  | sumExpression EQUAL sumExpression {$$ = ($1 == $3);}
                  | sumExpression {$$=$1;}
                  ;
    sumExpression : sumExpression ADD term {$$ = ($1 + $3); printf("%f",$$);}
                  | sumExpression SUBTRACT term {$$ = $1 - $3;}
                  | term {$$=$1;}
                  ;

    //sumop : ADD | SUBTRACT ;

     term : term MULTIPLY unaryExpression {$$ = $1 * $3;}
         | term DIVIDE unaryExpression {$$ = $1 / $3;}
         | unaryExpression {$$=$1;}
         ;

    unaryExpression : ADD unaryExpression {$$=+$2;}
                    | SUBTRACT unaryExpression {$$=-$2;}
                    | factor {$$=$1;};


    factor : immutable {$$=$1;} | mutable {$$=$1;} ;
    mutable : IDENTIFIER {checkScope(yylval.str); $$ = $1->value;}| mutable '[' expression ']' {$$=0;};
    immutable : '(' expression ')'{$$= $2;}| call { $$ = $1;} | const_type {$$=$1;};
    call : IDENTIFIER '(' args ')' {$$ = $1->value;
					check_parameter_list($1,param_list,p_idx); p_idx = 0;};
    args : argList | ;
    argList : argList ',' expression	
	    | expression ;

    const_type : DEC_CONSTANT { $$ = $1;curr_data_type = "FLOAT";}
               | INT_CONSTANT { $$ = $1;curr_data_type = "INT";}
               | HEX_CONSTANT { $$ = $1;curr_data_type = "INT";}

               ;
    identifier : IDENTIFIER {$1 = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level); $$ = $1;};
%%

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
    
    entry *res = Search(SymbolTable,extract,curr_nest_level);
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

void type_check(int left, int right, int flag)
{
	printf("DID COME HERE\n");
    printf("%d\t%d\n",left,right);
    if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
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


