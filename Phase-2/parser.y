// comment 
%{
    #include<stdio.h>
	  #include<stdlib.h>
	  #include "tables.h"
    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;
    int yyerror(char *msg);
    char* curr_data_type;
    int yylex(void);
%}

%union{
	int ival;
	char *str;
	entry *tbEntry;
	double dval;
}



/* Random Tokens I declared to silence errors */
%token SWITCH CASE DEFAULT STRUCT_UNI MAIN ADD SUBTRACT MULTIPLY DIVIDE ASSIGN GREATER_THAN LESSER_THAN MOD ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

/* Keywords */
%token VOID IF ELSE FOR DO WHILE GOTO BREAK CONTINUE RETURN

/* Data types */
%token INT SHORT LONG CHAR SIGNED UNSIGNED

/* Logical Operators */
%token LG_OR LG_AND NOT LESS_EQ GREATER_EQ

/* Relational Operators */
%token EQUAL

/* Assignment Operators */
%token DECREMENT INCREMENT NOT_EQ

/* Constants */
%token <dval> HEX_CONSTANT DEC_CONSTANT
%token <dval> INT_CONSTANT

/* String */
%token <str> STRING

/* Identifier */
%token <tbEntry> IDENTIFIER

// %type <dval> expression;
// %type <dval> simpleExpression;
// %type <dval> andExpression;
// %type <dval> unaryRelExpression;
// %type <dval> relExpression;
// %type <dval> sumExpression;
// %type <dval> term;
%type <dval> const_type;

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


%nonassoc UMINUS UPLUS
%nonassoc IFX
%nonassoc ELSE
%%
    /* Program is made up of declarations */
    program : declarationList;

    declarationList : declarationList declaration | declaration;

    declaration : varDeclaration | funDeclaration | strucUniDecl;

    strucUniDecl : STRUCT_UNI '{' varDeclaration '}' IDENTIFIER ';';

    varDeclaration : typeSpecifier varDeclList ';' ;

    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;

    varDeclInitialize : varDecId | varDecId ASSIGN STRING | varDecId ASSIGN assignmentExpression ;

    assignmentExpression : conditionalStmt | unaryExpression assignmentOperator assignmentExpression;

    varDecId : IDENTIFIER {$1->data_type = curr_data_type;} | IDENTIFIER '[' INT_CONSTANT ']';

    assignmentOperator : ASSIGN | ADD_ASSIGN | SUB_ASSIGN |MUL_ASSIGN|DIV_ASSIGN|MOD_ASSIGN;


    const_type : DEC_CONSTANT
               | INT_CONSTANT
               | HEX_CONSTANT
               ;

    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");}
                  | LONG INT
                  | CHAR {curr_data_type = strdup("CHAR");}
                  ;

  pointer : MULTIPLY pointer | MULTIPLY;

  funDeclaration : typeSpecifier IDENTIFIER '(' params ')' compoundStmt | typeSpecifier MAIN '(' params ')' compoundStmt | noDefDeclare ;

  noDefDeclare : typeSpecifier IDENTIFIER '(' params ')' ';';

  funCall : IDENTIFIER '(' params ')' statement;

  params : paramList | ;

  paramList :paramList ',' paramTypeList | paramTypeList ;

  paramTypeList : typeSpecifier paramId;

  paramId : IDENTIFIER | IDENTIFIER '[' ']';

  statement : labeledStmt | expressionStmt  | compoundStmt  | selectionStmt | iterationStmt | jumpStmt | returnStmt | breakStmt | funCall ;

  labeledStmt : IDENTIFIER ':' statement | CASE conditionalStmt ':' statement | DEFAULT ':' statement

  compoundStmt : '{' localDeclarations statementList '}' ;

  localDeclarations : localDeclarations varDeclaration |  ;

  statementList : statementList statement
                  |
                  ;

  expressionStmt : expression ';' | ';' ;

  selectionStmt : IF '(' simpleExpression ')' statement %prec IFX | IF '(' simpleExpression ')' statement ELSE statement | SWITCH '(' simpleExpression ')' statement;

  iterationStmt : WHILE '(' simpleExpression ')' statement | DO statement WHILE '(' expression ')' | FOR '(' optExpression ';' optExpression ';' optExpression ')' statement;

  optExpression : expression | ;

  jumpStmt : GOTO IDENTIFIER ';' | CONTINUE ';' ;

  returnStmt : RETURN ';' | RETURN expression ;

  breakStmt : BREAK ';' ;

  conditionalStmt : simpleExpression '?' expression ':' conditionalStmt  | simpleExpression;


  expression : IDENTIFIER assignmentOperator expression
             | INCREMENT IDENTIFIER
             | DECREMENT IDENTIFIER
             | simpleExpression
             ;
  simpleExpression : simpleExpression LG_OR andExpression  | andExpression ;

  andExpression : andExpression LG_AND unaryRelExpression | unaryRelExpression ;

  unaryRelExpression : NOT unaryRelExpression  | relExpression  ;

  relExpression : sumExpression GREATER_THAN sumExpression
                | sumExpression LESSER_THAN sumExpression
                | sumExpression LESS_EQ sumExpression
                | sumExpression GREATER_EQ sumExpression
                | sumExpression NOT_EQ sumExpression
                | sumExpression EQUAL sumExpression
                | sumExpression '|' sumExpression
                | sumExpression '&' sumExpression
                | sumExpression
                ;

   sumExpression : sumExpression ADD term
                 | sumExpression SUBTRACT term
                 | term
                 ;

    term : term MULTIPLY unaryExpression
       | term DIVIDE unaryExpression
       | term MOD unaryExpression
       | unaryExpression
       ;
  unaryExpression : unaryOp %prec UMINUS unaryExpression| factor ;

  unaryOp : UMINUS | '*'| UPLUS | '!' | '~' | '^' ;

  factor : IDENTIFIER | '(' expression ')' | const_type;


%%

#include "lex.yy.c"
int main(int argc , char *argv[]){

    SymbolTable = CreateTable();
    ConstantTable = CreateTable();

    // Open a file for parsing
    yyin = fopen(argv[1], "r");

    if(!yyparse())
    {
        printf("\nParsing complete\n");
    }
    else
    {
            printf("\nParsing failed\n");
    }
    printf("\n\tSymbol table");
    Display(SymbolTable);
    printf("\n\tConstant table");
    Display(ConstantTable);
    fclose(yyin);
    return 0;
}

int yyerror(char *msg)
{
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}
