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
    int typeCheck(entry*,entry*,char*);
    int checkFunc(char*);
    char* curr_data_type;
    int yylex(void);
    int is_loop = 0;
    int curr_nest_level = 1;
    int return_exists = 0;
    int is_param = 0;
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

    int stack[100] = {0};
    int top = 0;

    char ICGstack[100][20];
    int ICGtop = 0;

    int Labelstack[10];
    int Labeltop = 1;

    int is_call = 0;

    void push(char *text);

    void gencode();
    void gencode_unary();
    void gencode_if_statement();
    void gencode_if_if();
    void gencode_if_else();
    void gencode_while();
    void gencode_while_block();
    void gencode_for_modif();
    void gencode_for_eval();
    void gencode_for();
    void gencode_function(char *lexeme);
    void gencode_return();
    void gencode_param();
    
    int Registerlabel = 0;
    int line_instruction = 0;

    int Declarationlabel = 0;
    int valAssign;

    FILE *output;

    int is_for = 0;

    int loop_constants[2];

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
%token <tbEntry> HEX_CONSTANT DEC_CONSTANT INT_CONSTANT STRING
/* Identifier */
%token <tbEntry> IDENTIFIER 


 %type <tbEntry> identifier varDecId
 %type <tbEntry> mutable call factor expression simpleExpression andExpression sumExpression unaryExpression unaryRelExpression term immutable relExpression const_type


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
    
    varDeclInitialize : varDecId | varDecId assign_symbol simpleExpression {gencode(); $1->value = valAssign; typeCheck($1,$3,"="); is_declaration=1;} ;
    varDecId : identifier {$$=$1;} | identifier '[' INT_CONSTANT  ']' { if($3->value < 1){yyerror("Arrays can't have dimension lesser than 1");} $$=$1; $1->is_array = 1; $1->array_dim = (int)$3->value;};
    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");  is_declaration = 1; }
                  | VOID {curr_data_type = strdup("VOID");  is_declaration = 1; }
                  | CHAR {curr_data_type = strdup("CHAR");  is_declaration = 1;}
		          | FLOAT {curr_data_type = strdup("FLOAT");  is_declaration = 1;}
                  ;

    assign_symbol : ASSIGN {is_declaration = 0; push("=");}
    
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
                                                gencode_function($2->lexeme);
                                            }  
                     compoundStmt           { is_function = 0;
                                              if(!return_exists && strcmp(func_type,"VOID") != 0)
                                              {
                                                yyerror("This Function must have a return type");
                                                
                                              }
                                              fprintf(output,"func end\n");
					     };

     // Rules for parameter list
    params : paramList | ;
    paramList : paramList ',' paramTypeList | paramTypeList;
    paramTypeList : {is_param = 1; } typeSpecifier

                      paramId   {
                                              param_list[p_idx] = (char *)malloc(sizeof(curr_data_type));
                                              strcpy(param_list[p_idx++],curr_data_type);
                                              is_declaration = 0;
                                             
                                };
    paramId : identifier | identifier '[' ']';  
    // Types os statements in C
    statement : expressionStmt  | compoundStmt  | selectionStmt | iterationStmt | jumpStmt | returnStmt | breakStmt | varDeclaration ;

    // compound statements produces a list of statements with its local declarations
    compoundStmt : {curr_nest_level++; stack[top] = curr_nest_level; top+=1; insertNestStart(curr_nest_level,yylineno);} '{' statementList '}' {curr_nest_level++; insertNestEnd(stack[top-1],yylineno);top-=1;};
    statementList : statementList statement
                  |  ;
    // Expressions
    expressionStmt : expression ';' {ICGtop = 0;} | ';' {ICGtop=0;} ;
    selectionStmt : IF '(' simpleExpression ')' {gencode_if_statement();} compoundStmt  else 
                  ;
    
    else : {gencode_if_else();}ELSE statement  | ;

    iterationStmt : WHILE '(' simpleExpression ')' {gencode_while();} {is_loop = 1;} statement { gencode_while_block(); is_loop = 0;}
                  | DO {is_loop = 1;}statement WHILE '(' expression ')' ';' {is_loop = 0;}
                  | FOR '(' optExpression ';' optExpression {gencode_for_eval();} ';' {is_for = 1;} optExpression {is_for = 0;}  ')'{is_loop = 1;} statement {is_loop = 0;gencode_for_modif();};
    // Optional expressions in case of for
    optExpression : expression | ;

    jumpStmt : GOTO identifier ';' | CONTINUE ';' {if(!is_loop) {yyerror("Illegal use of continue");} fprintf(output,"goto L%d\n",loop_constants[1]); };
    returnStmt : RETURN ';'  { if(is_function) { if(strcmp(func_type,"VOID")!=0) yyerror("return type (VOID) does not match function type");}}

               | RETURN expression {
                                      return_exists = 1;
                                      if(strcmp(curr_data_type,$2->data_type)!=0)
                                        yyerror("return type does not match function type");
                                      else
                                        gencode_return();
                                   } ;
    breakStmt : BREAK ';' {if(!is_loop) {yyerror("Illegal use of break");} fprintf(output,"goto L%d\n",loop_constants[0]); };

    expression : mutable ASSIGN {push("=");}  expression {typeCheck($1,$4,"=");$$ = $1;gencode(); $1->value = valAssign;}
               | mutable ADD_ASSIGN {push("+=");} expression {typeCheck($1,$4,"+=");$$ = $1;gencode();$1->value = valAssign;}
               | mutable SUB_ASSIGN {push("-=");} expression {typeCheck($1,$4,"-=");$$ = $1;gencode();$1->value = valAssign;}
               | mutable MUL_ASSIGN {push("*=");} expression {typeCheck($1,$4,"*=");$$ = $1;gencode(); $1->value = valAssign;}
               | mutable DIV_ASSIGN {push("/=");} expression {typeCheck($1,$4,"/=");$$ = $1;gencode(); $1->value = valAssign;}
               | mutable INCREMENT {typeCheck($1,$1,"++"); $$ = $1;}
               | mutable DECREMENT {typeCheck($1,$1,"--"); $$ = $1;}
               | simpleExpression { $$ = $1;} 
               ;

    simpleExpression : simpleExpression LG_OR  andExpression {typeCheck($1,$3,"||"); $$ = $1;{push("||");}gencode();} 
                     | andExpression { $$ = $1;};

    andExpression : andExpression LG_AND  unaryRelExpression { typeCheck($1,$3,"&&");$$ = $1;{push("&&");}gencode();} 
                  | unaryRelExpression { $$ = $1;} ;

    unaryRelExpression : NOT unaryRelExpression { typeCheck($2,$2,"!u");$$ = $2;{push("!");} }
                       | relExpression { $$ = $1;} ;

    relExpression : sumExpression GREATER_THAN  sumExpression {typeCheck($1,$3,">");$$ = $1;{push(">");}gencode();}
                  | sumExpression LESSER_THAN  sumExpression {typeCheck($1,$3,"<");$$ = $1;{push("<");}gencode();} 
                  | sumExpression LESS_EQ  sumExpression {typeCheck($1,$3,"<=");$$ = $1;{push("<=");}gencode();}
                  | sumExpression GREATER_EQ  sumExpression {typeCheck($1,$3,">=");$$ = $1;{push(">=");}gencode();}
                  | sumExpression NOT_EQ  sumExpression {typeCheck($1,$3,"!=");{push("!=");} gencode();}
                  | sumExpression EQUAL  sumExpression {typeCheck($1,$3,"==");$$ = $1; {push("==");} gencode();}
                  | sumExpression { $$ = $1;}
                  ;
    sumExpression : sumExpression ADD  term {typeCheck($1,$3,"+");$$ = $1;{push("+");}gencode();}
                  | sumExpression SUBTRACT term {typeCheck($1,$3,"-");$$ = $1;{push("-");} gencode(); }
                  | term { $$ = $1;}
                  ;

   

    term : term MULTIPLY  unaryExpression {typeCheck($1,$3,"*");$$ = $1; {push("*");}gencode();}
         | term DIVIDE  unaryExpression {typeCheck($1,$3,"/");$$ = $1; {push("/");}gencode();}
         | unaryExpression { $$ = $1;}
         ;

    unaryExpression : ADD   factor { typeCheck($2,$2,"+u");$$ = $2; {push("+");}gencode_unary();}
                    | SUBTRACT  factor { typeCheck($2,$2,"-u");$$ = $2; {push("-");}gencode_unary();}
                    | factor { $$ = $1;} ;


    factor : immutable {$$ = $1;} | mutable {$$ = $1;};
    mutable : identifier {if(checkScope(yylval.str) == 0){ return -1;}; $$ = $1;}| identifier '[' simpleExpression ']' {if($3->value < 0 || $3->value >= $1->array_dim ){yyerror("Exceeds Array Dimensions\n"); } $$ = $1;}
    immutable : '(' expression ')' { $$ = $2;}| call {$$=$1;} | const_type {$$=$1;} ;
    call : identifier  '(' args ')' { 
                                      if(checkFunc($1->lexeme) == 0)
                                        {return -1;};
                                      $$ = $1;
                                      check_parameter_list($1,arg_list,a_idx);
                                      a_idx = 0;
                                      fprintf(output,"refparam result\n");
                                      {fprintf(output,"call %s,%d\n",$1->lexeme,$1->num_params);}
                                      is_call = 1;
                                    }
    args : argList  | ;
  
    argList : argList ',' arg 
	    | arg ;

    arg : expression     {
                            arg_list[a_idx] = (char *)malloc(sizeof($1));
                            strcpy(arg_list[a_idx++],$1->data_type);

                            gencode_param();
                            
                        }
          ;

    const_type : DEC_CONSTANT { $$ = $1;push($1->lexeme);}
               | INT_CONSTANT { $$ = $1;push($1->lexeme);}
               | HEX_CONSTANT { $$ = $1;push($1->lexeme);}
               | STRING       { $$ = $1;push($1->lexeme);}  
               ;
    identifier : IDENTIFIER { 
					if(is_declaration){
					// $1 = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
					$$ = $1;
                    is_function = 0;
                    push($1->lexeme);
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
                    push($1->lexeme);
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

int typeCheck(entry *a,entry *b,char *c){
	
	if(strcmp(a->data_type,b->data_type)!=0){
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
    DisplayConstant(ConstantTable);
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
    entry *res = ScopeSearch(SymbolTable,extract,curr_nest_level);
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
        int startLine = -1;
        if(Nester[level] == NULL)
        {
            startLine = 0;
            endLine = yylineno + 100;
        }   
        else
        {
            startLine = Nester[level]->line_start;
            endLine = Nester[level]->line_end;
        }


        if((yylineno <= endLine && yylineno >= startLine))
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

    system("clear");

    SymbolTable = CreateTable();
    ConstantTable = CreateTable();
    nested_homekeeping();
    int i;
    // Open a file for parsing
    yyin = fopen(argv[1], "r");

    output = fopen("ICG.code","w");  

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
    fprintf(output,"exit\n");
    fclose(output);
    // system("clear");
    printf("_________________________________________\n\n");
    printf("\tIntermediate Three Address Code\n\n");
    system("cat ICG.code");
    printf("_________________________________________\n");
    return 0;
}

int yyerror(char *msg)
{
  // Function to display error messages with line no and token
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}

void push(char *text)
{
    strcpy(ICGstack[ICGtop++],text);
}

void gencode()
{

    if(is_for == 1)
    {
        gencode_for();
    }
    else
    {
        
    char *op1 = ICGstack[--ICGtop]; 
    char *op2 = ICGstack[--ICGtop];
    char *op3 = ICGstack[--ICGtop];
    
    if( strcmp(op2,"=")== 0)
    {
        if(is_call == 0)
        {
            fprintf(output,"%s = %s\n",op3,op1);
            is_call = 0;
        }
        else
        {
           fprintf(output,"%s = result\n",op3);
           --ICGtop;
        }
    }
    else if(strcmp(op2,"+=") == 0)
    {
        fprintf(output,"%s = %s + %s\n",op3,op3,op1);
           
    }
    else if(strcmp(op2,"-=") == 0)
    {
        fprintf(output,"%s = %s - %s\n",op3,op3,op1);   
    }
    else if(strcmp(op2,"*=") == 0)
    {
        fprintf(output,"%s = %s * %s\n",op3,op3,op1);   
    }
    else if(strcmp(op2,"/=") == 0)
    {
        fprintf(output,"%s = %s / %s\n",op3,op3,op1);
    }
    else
    {
        char temp[3] = "t0\0";
        temp[1] = (char)(Registerlabel + '0');
        temp[2] = '\0';
        Registerlabel++;

        fprintf(output,"%s = %s %s %s\n",temp,op3,op1,op2);
        if(strcmp(op1,"+") == 0)
            valAssign = atoi(op3) + atoi(op2);
        else if(strcmp(op1,"-") == 0)
            valAssign = atoi(op3) - atoi(op2);
        else if(strcmp(op1,"*") == 0)
            valAssign = atoi(op3) * atoi(op2);
        else if(strcmp(op1,"/") == 0)
            valAssign = atoi(op3) / atoi(op2);

        push(temp);
    } 
    }
    line_instruction++;
}

void gencode_for()
{
    char *op1 = ICGstack[--ICGtop]; 
    char *op2 = ICGstack[--ICGtop];
    char *op3 = ICGstack[--ICGtop];
    
    FILE *output1 = fopen("modtemp.code","a");

    if( strcmp(op2,"=")== 0)
    {
        fprintf(output1,"%s = %s\n",op3,op1);
    }
    else if(strcmp(op2,"+=") == 0)
    {
        fprintf(output1,"%s = %s + %s\n",op3,op3,op1);   
    }
    else if(strcmp(op2,"-=") == 0)
    {
        fprintf(output1,"%s = %s - %s\n",op3,op3,op1);   
    }
    else if(strcmp(op2,"*=") == 0)
    {
        fprintf(output1,"%s = %s * %s\n",op3,op3,op1);   
    }
    else if(strcmp(op2,"/=") == 0)
    {
        fprintf(output1,"%s = %s / %s\n",op3,op3,op1);
    }
    else
    {
        char temp[3] = "t0\0";
        temp[1] = (char)(Registerlabel + '0');
        temp[2] = '\0';
        Registerlabel++;

        fprintf(output1,"%s = %s %s %s\n",temp,op3,op1,op2);

        push(temp);
    } 
    line_instruction++;  
    fclose(output1);
}

void gencode_unary()
{
    line_instruction++;
    char *op1 = ICGstack[--ICGtop]; 
    char *op2 = ICGstack[--ICGtop];

    char temp[3] = "t0\0";
    temp[1] = (char)(Registerlabel + '0');
    temp[2] = '\0';
    Registerlabel++;

    fprintf(output,"%s = %s %s\n",temp,op1,op2);

    push(temp);
    line_instruction++;  
}

void gencode_if_statement()
{
    Labelstack[Labeltop++] = ++Declarationlabel;
    fprintf(output,"if %s goto L%d\n",ICGstack[--ICGtop],Declarationlabel);

    gencode_if_if();

}

void gencode_if_if()
{
    ++Declarationlabel;
    fprintf(output,"goto L%d\n",Declarationlabel);
    fprintf(output,"L%d :\n",Labelstack[--Labeltop]);
    Labelstack[Labeltop++] = Declarationlabel;
}

void gencode_if_else()
{
    fprintf(output,"L%d :\n",Labelstack[--Labeltop]);
}

void gencode_while()
{
    
    fprintf(output,"L%d :\n",++Declarationlabel);
    loop_constants[0] = Declarationlabel;
    Labelstack[Labeltop++] = Declarationlabel; 
    Labelstack[Labeltop++] = ++Declarationlabel;
    fprintf(output,"if %s goto L%d\n",ICGstack[--ICGtop],Declarationlabel);

    ++Declarationlabel;
    fprintf(output,"goto L%d\n",Declarationlabel);
    loop_constants[1]= Declarationlabel;
    fprintf(output,"L%d :\n",Labelstack[--Labeltop]);
    Labelstack[Labeltop++] = Declarationlabel;
}

void gencode_while_block()
{
    int l_otherwise = Labelstack[--Labeltop];
    int l_while = Labelstack[--Labeltop];
    fprintf(output,"goto L%d\n",l_while);
    fprintf(output,"L%d :\n",l_otherwise);
}

void gencode_for_eval()
{
    fprintf(output,"L%d :\n",++Declarationlabel);
    loop_constants[0] = Declarationlabel;
    Labelstack[Labeltop++] = Declarationlabel; 
    Labelstack[Labeltop++] = ++Declarationlabel;
    fprintf(output,"if %s goto L%d\n",ICGstack[--ICGtop],Declarationlabel);

    ++Declarationlabel;
    fprintf(output,"goto L%d\n",Declarationlabel);
    loop_constants[1] = Declarationlabel;
    fprintf(output,"L%d :\n",Labelstack[--Labeltop]);
    Labelstack[Labeltop++] = Declarationlabel;
}

void gencode_for_modif()
{
    
    FILE *output1 = fopen("modtemp.code","r");

    char c = fgetc(output1);
    while(c != EOF)
    {
        fprintf(output,"%c",c);
        c = fgetc(output1);
    }

    fclose(output1);

    system("rm modtemp.code");

    int l_otherwise = Labelstack[--Labeltop];
    int l_for = Labelstack[--Labeltop];

    fprintf(output,"goto L%d\n",l_for);
    fprintf(output,"L%d :\n",l_otherwise);
    
}

void gencode_function(char *lexeme)
{
    fprintf(output,"func begin %s\n",lexeme);
}

void gencode_return()
{
    fprintf(output,"return %s\n",ICGstack[--ICGtop]);
}

void gencode_param()
{
    fprintf(output,"Param %s\n",ICGstack[--ICGtop]);
}
