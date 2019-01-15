%{
    #include<stdio.h>
    #include<stdlib.h>
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

"int"                               {printf("\t%-50s : Keyword\n", yytext);}
"short"                             {printf("\t%-50s : Keyword\n", yytext);}
"long"                              {printf("\t%-50s : Keyword\n", yytext);}
"char"                              {printf("\t%-50s : Keyword\n", yytext);}
"signed"                            {printf("\t%-50s : Keyword\n", yytext);}
"unsigned"                          {printf("\t%-50s : Keyword\n", yytext);}
"void"                              {printf("\t%-50s : Keyword\n", yytext);}
"if"                                {printf("\t%-50s : Keyword\n", yytext);}
"else"                              {printf("\t%-50s : Keyword\n", yytext);}
"for"                               {printf("\t%-50s : Keyword\n", yytext);}
"do"                                {printf("\t%-50s : Keyword\n", yytext);}
"while"                             {printf("\t%-50s : Keyword\n", yytext);}
"goto"                              {printf("\t%-50s : Keyword\n", yytext);}
"break"                             {printf("\t%-50s : Keyword\n", yytext);}
"continue"                          {printf("\t%-50s : Keyword\n", yytext);}
"main"                              {printf("\t%-50s : Keyword\n", yytext);}
"return"                            {printf("\t%-50s : Keyword\n", yytext);}


 /* Constants */

[+/-]?[0][x|X]{hex}+                {printf("\t%-50s : Hexadecimal Constant\n", yytext);}
[+/-]?{digit}+                      {printf("\t%-50s : Integer Constant\n", yytext);}
[+/-]?({digit}+)["."]({digit}+)     {printf("\t%-50s : Decimal Constant\n", yytext);}


{identifier} {
  if(strlen(yytext) <= 32)
    printf("\t%-50s : Identifier\n", yytext); 
  else 
    printf("Error %d: Identifier too long,must be between 1 to 32 characters", yylineno);
}


{digit}+({letter}|_)+               {printf("Error %d: Illegal identifier format\n", yylineno);}
{whitespace}                        ;


 /* Preprocessor Directives */

^"#include"                         {BEGIN PREPROCESSOR;}
<PREPROCESSOR>{whitespace}          ;
<PREPROCESSOR>"<"[^<>\n]*">"        {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"          {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>"\n"                  {printf("Error %d: Header format not allowed\n", yylineno); yylineno++; BEGIN INITIAL;}
<PREPROCESSOR>.                     {printf("Error %d: Header format not allowed\n", yylineno); BEGIN INITIAL;}


 /* Macropreprocessor Directives */

^"#define"                                        {BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace}                   ;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {printf("\t%-50s : Macropreprocessor directive\n", yytext); BEGIN INITIAL;}
<MACROPREPROCESSOR>\n                             {yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>.                              {printf("Error %d: Invalid definition\n", yylineno); BEGIN INITIAL;}


 /* Comments */

"/*"                                {BEGIN COMMENT;}
<COMMENT>.|{whitespace}             ;
<COMMENT>\n                         {yylineno++;}
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error %d: Nested comments are invalid\n", yylineno); yyterminate();}
<COMMENT><<EOF>>                    {printf("Error %d: Unterminated comments are invalid\n", yylineno); yyterminate();}
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

\"[^\"\n]*$                         {printf("Error %d: Illegally terminated string\n", yylineno); yyterminate();}
\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
    printf("\t%-50s : String\n", yytext);
  }
  else
    printf("\t%-50s : String\n", yytext);
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
.                                   {printf("Error %d: Illegal character\n", yylineno);}


%%


int main(int argc, char *argv[])
{
  FILE *fh;
  if (argc == 2 && (fh = fopen(argv[1], "r")))
        yyin = fh;
  yyin = fopen("test-case-errors.c", "r");
  yylex();
  printf("Lexical analysis finished\n");
  return 0;
}

int yywrap(){return 1;}
