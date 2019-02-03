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
%token MAIN ADD SUBTRACT MULTIPLY DIVIDE ASSIGN GREATER_THAN LESSER_THAN

/* Keywords */
%token VOID IF ELSE FOR DO WHILE GOTO BREAK CONTINUE RETURN

/* Data types */
%token INT SHORT LONG CHAR SIGNED UNSIGNED

/* Logical Operators */
%token LG_OR LG_AND NOT LESS_EQ GR_EQ

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
%start program

%left ','
%right '='
%left LG_OR
%left LG_AND
%left EQUAL NOT_EQ
%left '<' '>' LESS_EQ GR_EQ
%left '+' '-'
%left '*' '/' '%'
%right NOT

%%
    program : declarationList declaration
            | declaration;

    declarationList : declarationList declaration
                    | declaration;

    declaration : varDeclaration;

    varDeclaration : typeSpecifier IDENTIFIER ';'
                   | typeSpecifier IDENTIFIER ASSIGN const_type ';'
									;

    const_type : DEC_CONSTANT
               | INT_CONSTANT
               | HEX_CONSTANT ;

    typeSpecifier : INT
                  | LONG INT
                  | CHAR ;



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
