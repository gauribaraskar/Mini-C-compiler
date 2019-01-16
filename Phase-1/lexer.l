%{
    #include<stdio.h>
    #include<stdlib.h>

    #include "tables.h"

    entry **SymbolTable = NULL;
    entry **ConstantTable = NULL;

    int ErrFlag = 0;
%}


 /* Declarations */

letter [a-zA-Z]
digit [0-9]
whitespace [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_)*
hex [0-9a-fA-F]


 /* States */

%x PREPROCESSOR
%x MACROPREPROCESSOR
%x COMMENT
%x SLCOMMENT

%%


 /* Keywords */

"int"                               {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"short"                             {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"long"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"char"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"signed"                            {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"unsigned"                          {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"void"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"if"                                {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"else"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"for"                               {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"do"                                {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"while"                             {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"goto"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"break"                             {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"continue"                          {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"main"                              {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}
"return"                            {printf("\t%-50s : Keyword\n", yytext);InsertEntry(SymbolTable,yytext,"KEYWORD");}


 /* Constants */

[+/-]?[0][x|X]{hex}+                {printf("\t%-50s : Hexadecimal Constant\n", yytext); InsertEntry(ConstantTable,yytext,"HEX_CONSTANT");}
[+/-]?{digit}+                      {printf("\t%-50s : Integer Constant\n", yytext); InsertEntry(ConstantTable,yytext,"INT_CONSTANT");}
[+/-]?({digit}+)["."]({digit}+)     {printf("\t%-50s : Decimal Constant\n", yytext); InsertEntry(ConstantTable,yytext,"DEC_CONSTANT");}


{identifier} {
  if(strlen(yytext) <= 32)
    {
      printf("\t%-50s : Identifier\n", yytext);
      InsertEntry(SymbolTable,yytext,"IDENTIFIER");
    }
  else
  {
      printf("Error %d: Identifier too long,must be between 1 to 32 characters\n", yylineno);
      ErrFlag = 1;
  }
}


{digit}+({letter}|_)+               {printf("Error %d: Illegal identifier format\n", yylineno); ErrFlag = 1;}
{whitespace}                        ;


 /* Preprocessor Directives */

^"#include"                         {BEGIN PREPROCESSOR;}
<PREPROCESSOR>{whitespace}          ;
<PREPROCESSOR>"<"[^<>\n]*">"        {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"          {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>"\n"                  {printf("Error %d: Header format not allowed\n", yylineno); yylineno++; BEGIN INITIAL;ErrFlag=1;}
<PREPROCESSOR>.                     {printf("Error %d: Header format not allowed\n", yylineno); ErrFlag=1;}


 /* Macropreprocessor Directives */

^"#define"                                        {BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace}                   ;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {printf("\t%-50s : Macropreprocessor directive\n", yytext); BEGIN INITIAL;}
<MACROPREPROCESSOR>\n                             {yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>.                              {printf("Error %d: Invalid definition\n", yylineno); BEGIN INITIAL;ErrFlag=1;}


 /* Comments */

"/*"                                {BEGIN COMMENT;}
<COMMENT>.|{whitespace}             ;
<COMMENT>\n                         {yylineno++;}
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error %d: Nested comments are invalid\n", yylineno); ErrFlag=1;yyterminate();}
<COMMENT><<EOF>>                    {printf("Error %d: Unterminated comments are invalid\n", yylineno);ErrFlag=1; yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {yylineno++; BEGIN INITIAL;}


 /* Operators */

"+"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"-"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"*"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"/"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"="                                 {printf("\t%-50s : Assignment Operator\n", yytext);}
"--"                                {printf("\t%-50s : Decrement Operator\n", yytext);}
"++"                                {printf("\t%-50s : Increment Operator\n", yytext);}

">"                                 {printf("\t%-50s : Comparison Operator\n", yytext);}
"<"                                 {printf("\t%-50s : Comparison Operator\n", yytext);}
">="                                {printf("\t%-50s : Comparison Operator\n", yytext);}
"<="                                {printf("\t%-50s : Comparison Operator\n", yytext);}
"=="                                {printf("\t%-50s : Comparison Operator\n", yytext);}

"||"                                {printf("\t%-50s : Boolean Operator\n", yytext);}
"&&"                                {printf("\t%-50s : Boolean Operator\n", yytext);}
"!"                                 {printf("\t%-50s : Boolean Operator\n", yytext);}


 /* Strings and Characters */

\"[^\"\n]*$                         {printf("Error %d: Illegally terminated string\n", yylineno);ErrFlag=1; yyterminate();}
\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
  }
  else
  {
    InsertEntry(ConstantTable,yytext,"STRING");
    printf("\t%-50s : String\n", yytext);
  }
}

\'[^\'\n]\'                         {printf("\t%-50s : Character\n", yytext);}


 /* Punctuators */


"["                                 {printf("\t%-50s : Open Square Bracket\n", yytext);}
"]"                                 {printf("\t%-50s : Closed Square Bracket\n", yytext);}
"{"                                 {printf("\t%-50s : Open Curly Bracket\n", yytext);}
"}"                                 {printf("\t%-50s : Closed Curly Bracket\n", yytext);}
"("                                 {printf("\t%-50s : Open Round Bracket\n", yytext);}
")"                                 {printf("\t%-50s : Closed Round Bracket\n", yytext);}
","                                 {printf("\t%-50s : Comma\n", yytext);}
";"                                 {printf("\t%-50s : Delimiter\n", yytext);}


"\n"                                {yylineno++;}
.                                   {printf("Error %d: Illegal character\n", yylineno);ErrFlag=1;}


%%


int main(int argc, char *argv[])
{
  SymbolTable = CreateTable();
  ConstantTable = CreateTable();
  FILE *fh;
  if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
  yylex();

  if (ErrFlag == 0)
  {
    printf("\nPrinting Symbol Table\n" );
    Display(SymbolTable);
    printf("\n\n");
    printf("Printing Constant Table\n" );
    Display(ConstantTable);
  }

  printf("Lexical analysis finished\n");
  return 0;
}

int yywrap(){return 1;}
