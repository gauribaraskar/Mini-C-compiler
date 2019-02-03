// Pointers , strings , chracters, comma declaration , array declaration
%{
    #include<stdio.h>
	#include<stdlib.h>
	#include "tables.h"
    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;
    int yyerror(char *msg);
    int yylex(void);
%}

%union{
	int ival;
	char *str;
	entry *tbEntry;
	double dval;
}

/* Random Tokens I declared to silence errors */
%token MAIN ADD SUBTRACT MULTIPLY DIVIDE ASSIGN GREATER_THAN LESSER_THAN MOD

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
%token <ival> INT_CONSTANT

/* String */
%token <str> STRING

/* Identifier */
%token <tbEntry> IDENTIFIER
%start statement

%left ','
%right ASSIGN
%left LG_OR
%left LG_AND
%left EQUAL NOT_EQ
%left LESSER_THAN GREATER_THAN LESS_EQ GREATER_EQ
%left ADD SUBTRACT
%left MULTIPLY DIVIDE MOD
%right NOT

%%
    program : declarationList;

    declarationList : declarationList declaration | declaration;

    declaration : varDeclaration;

    varDeclaration : typeSpecifier varDeclList ';' 

    varDeclList : varDeclList ',' varDeclInitialize | varDeclInitialize;

    varDeclInitialize : varDecId | varDecId ASSIGN simpleExpression ;

    varDecId : IDENTIFIER;
									 

    const_type : DEC_CONSTANT
               | INT_CONSTANT
               | HEX_CONSTANT ;

    typeSpecifier : INT
                  | LONG INT
                  | CHAR ;

expression : IDENTIFIER ASSIGN expression | IDENTIFIER INCREMENT | IDENTIFIER DECREMENT | simpleExpression;

simpleExpression : simpleExpression LG_OR andExpression | andExpression;

andExpression : andExpression LG_AND unaryRelExpression | unaryRelExpression;

unaryRelExpression : NOT unaryRelExpression | relExpression ;

relExpression : sumExpression relop sumExpression | sumExpression ;

relop : GREATER_THAN | LESSER_THAN | LESS_EQ | GREATER_EQ | NOT_EQ | EQUAL ;

sumExpression : sumExpression sumop term | term ;

term : term mulop factor | factor ;

mulop : MULTIPLY | DIVIDE | MOD ;

sumop : ADD | SUBTRACT ;

factor : IDENTIFIER |'(' expression ')'|const_type ;

statement : expressionStmt | compoundStmt | selectionStmt | iterationStmt | returnStmt | breakStmt ; 

expressionStmt : expression ';' | ';' ;

compoundStmt : '{' statementList '}' ;

statementList : statementList statement 
                | 
                ;

selectionStmt : IF '(' simpleExpression ')' statement | IF '(' simpleExpression ')' statement ELSE statement ;

iterationStmt : WHILE '(' simpleExpression ')' statement | DO statement WHILE '(' expression ')' | FOR '(' expression ';' expression ';' expression ')' statement

returnStmt : RETURN ';' | RETURN expression ;

breakStmt : BREAK ';' ;



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
    fclose(yyin);
    return 0;
}

int yyerror(char *msg)
{
    printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
    return 0;
}
