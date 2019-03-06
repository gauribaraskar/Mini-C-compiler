/* The file describes the grammar for our parser */

%{
    // Header files
    #include<stdio.h>
      #include<stdlib.h>
      #include "tables.h"

    // Initialising Symbol table and constant table
    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;

    int yyerror(char *msg);
    char* curr_data_type;
    int yylex(void);
%}

// Data types of tokens
%union{
    int ival;
    char *str;
    entry *tbEntry;
    double dval;
}

/* Operators */
%token ADD SUBTRACT MULTIPLY DIVIDE ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN  MOD
/* Relational Operators */
%token GREATER_THAN LESSER_THAN LESS_EQ GREATER_EQ NOT_EQ EQUAL
/* Keywords */
%token VOID IF ELSE FOR DO WHILE GOTO BREAK CONTINUE RETURN SWITCH CASE DEFAULT  MAIN
/* Data types */
%token INT SHORT LONG CHAR SIGNED UNSIGNED
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
    varDeclaration : typeSpecifier varDeclList ';' ;
    // Variables can also be initialised during declaration
    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;
    // Assigment can be through a simple expression or conditional statement
    varDeclInitialize : varDecId | varDecId ASSIGN assignmentExpression ;
    varDecId : IDENTIFIER {$1->data_type = curr_data_type;} | IDENTIFIER '[' INT_CONSTANT ']';
    assignmentExpression : conditionalStmt | unaryExpression assignmentOperator assignmentExpression ;
    assignmentOperator : ASSIGN | ADD_ASSIGN | SUB_ASSIGN |MUL_ASSIGN|DIV_ASSIGN|MOD_ASSIGN;

    // Types for constants
    const_type : DEC_CONSTANT
               | INT_CONSTANT
               | HEX_CONSTANT
               | STRING
               ;
    // data types
    typeSpecifier : typeSpecifier pointer
                  | INT {curr_data_type = strdup("INT");}
                  | LONG INT
                  | VOID
                  | CHAR {curr_data_type = strdup("CHAR");}
                  ;
    // Pointer declaration
    pointer : MULTIPLY pointer | MULTIPLY;

    // Function declaration
    funDeclaration : typeSpecifier IDENTIFIER '(' params ')' compoundStmt | typeSpecifier MAIN '(' params ')' compoundStmt | noDefDeclare ;
    noDefDeclare : typeSpecifier IDENTIFIER '(' params ')' ';';
    funCall : IDENTIFIER '(' args ')' ';';

    args : argList | ;
    argList : argList ',' expression | expression;

    // Rules for parameter list
    params : paramList | ;
    paramList :paramList ',' paramTypeList | paramTypeList ;
    paramTypeList : typeSpecifier paramId;
    paramId : IDENTIFIER | IDENTIFIER '[' ']';

    // Types os statements in C
    statement : labeledStmt | expressionStmt  | compoundStmt  | selectionStmt | iterationStmt | jumpStmt | returnStmt | breakStmt | funCall;

    // Matches label for goto and grammar for switch statement
    labeledStmt : IDENTIFIER ':' statement | CASE conditionalStmt ':' statement | DEFAULT ':' statement

    // compound statements produces a list of statements with its local declarations
    compoundStmt : '{' localDeclarations statementList '}';
    localDeclarations : localDeclarations statementList varDeclaration
                      |  ;
    statementList : statementList statement
                  |  ;
    // Expressions
    expressionStmt : expression ';' | ';' ;
    selectionStmt : IF '(' simpleExpression ')' statement %prec IFX
                  | IF '(' simpleExpression ')' statement ELSE statement
                  | SWITCH '(' simpleExpression ')' statement;

    iterationStmt : WHILE '(' simpleExpression ')' statement
                  | DO statement WHILE '(' expression ')' ';'
                  | FOR '(' optExpression ';' optExpression ';' optExpression ')' statement;
    // Optional expressions in case of for
    optExpression : expression | ;

    jumpStmt : GOTO IDENTIFIER ';' | CONTINUE ';' ;
    returnStmt : RETURN ';'
               | RETURN expression ;
    breakStmt : BREAK ';' ;

    conditionalStmt : simpleExpression '?' expression ':' conditionalStmt  | simpleExpression;


    // All arithmetic expressions
    expression : IDENTIFIER assignmentOperator assignmentExpression
               | INCREMENT IDENTIFIER
               | DECREMENT IDENTIFIER
               | simpleExpression
               ;
    simpleExpression : simpleExpression LG_OR andExpression
                     | andExpression ;
    andExpression : andExpression LG_AND unaryRelExpression
                  | unaryRelExpression ;
    unaryRelExpression : NOT unaryRelExpression
                       | relExpression  ;
    relExpression : sumExpression GREATER_THAN sumExpression
                  | sumExpression LESSER_THAN sumExpression
                  | sumExpression LESS_EQ sumExpression
                  | sumExpression GREATER_EQ sumExpression
                  | sumExpression NOT_EQ sumExpression
                  | sumExpression EQUAL sumExpression
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
    unaryExpression : unaryOp unaryExpression
                    | factor ;

    unaryOp : ADD | SUBTRACT ;

    factor : IDENTIFIER | '(' expression ')' | const_type;
%%
void disp()
{
    printf("\n\tSymbol table");
    Display(SymbolTable);
    printf("\n\tConstant table");
    Display(ConstantTable);
}
#include "lex.yy.c"
int main(int argc , char *argv[]){
    SymbolTable = CreateTable();
    ConstantTable = CreateTable();
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
