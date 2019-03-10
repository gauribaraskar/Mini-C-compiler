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
    char* curr_data_type;
    int yylex(void);
    int is_bool = 1;
    int isfunDec = 0;
    int curr_nest_level = 1;

    extern int yylineno;
    extern char* yytext;

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
    /* Program is made up of declarations */
    program : declarationList;
    // Program can have multiple declarations
    declarationList : declarationList declaration | declaration;
    // Types of declaration in C
    declaration : varDeclaration | funDeclaration ;
    // Variable declarations
    /* Variable declaration can be a list */
    varDeclaration : {isfunDec = 0;}typeSpecifier varDeclList ';' ;
    // Variables can also be initialised during declaration
    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;
    // Assigment can be through a simple expression or conditional statement
    varDeclInitialize : varDecId | varDecId ASSIGN simpleExpression ;
    varDecId : identifier | identifier '[' INT_CONSTANT ']';
    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");}
                  | VOID {curr_data_type = strdup("VOID");}
                  | CHAR {curr_data_type = strdup("CHAR");}
                  ;

    //assignmentExpression : conditionalStmt | unaryExpression assignmentOperator assignmentExpression ;
    //assignmentOperator : ASSIGN | ADD_ASSIGN | SUB_ASSIGN |MUL_ASSIGN|DIV_ASSIGN|MOD_ASSIGN;
    // Types for constants


    // Pointer declaration
    pointer : MULTIPLY pointer | MULTIPLY;

    // Function declaration
    funDeclaration : typeSpecifier {isfunDec=1;} identifier  '(' params ')' statement 
    | IDENTIFIER '(' params ')' statement ;

     // Rules for parameter list
    params : paramList | ;
    paramList : paramList ',' paramTypeList | paramTypeList;
    paramTypeList : typeSpecifier paramId;
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

    expression : mutable ASSIGN expression {$1 = $3;}
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
    mutable : IDENTIFIER {checkScope(yylval.str); $$=$1->value;}| mutable '[' expression ']'{$$=0;} ;
    immutable : '(' expression ')' {$$=$2;} | call {$$=$1;}| const_type {$$=$1;};
    call : IDENTIFIER '(' args ')'{$$=0;} ;
    args : argList | ;
    argList : argList ',' expression | expression;

    const_type : DEC_CONSTANT { $$ = $1;}
               | INT_CONSTANT { $$ = $1;}
               | HEX_CONSTANT { $$ = $1;}

               ;
    identifier : IDENTIFIER {if(isfunDec){
        entry* ent = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
        ent->is_function = 1;
        printf("FUNCTION");
        isfunDec = 0;
        }
        else
        {
            entry* ent = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,curr_nest_level);
        ent->is_function = 0;
        } 
    }
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
