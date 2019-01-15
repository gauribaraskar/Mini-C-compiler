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

"int"           {printf("\t%-50s : Keyword\n", yytext);}
"short"         {printf("\t%-50s : Keyword\n", yytext);}
"long"          {printf("\t%-50s : Keyword\n", yytext);}
"char"          {printf("\t%-50s : Keyword\n", yytext);}
"signed"        {printf("\t%-50s : Keyword\n", yytext);}
"unsigned"      {printf("\t%-50s : Keyword\n", yytext);}
"void"          {printf("\t%-50s : Keyword\n", yytext);}
"if"            {printf("\t%-50s : Keyword\n", yytext);}
"else"          {printf("\t%-50s : Keyword\n", yytext);}
"for"           {printf("\t%-50s : Keyword\n", yytext);}
"do"            {printf("\t%-50s : Keyword\n", yytext);}
"while"         {printf("\t%-50s : Keyword\n", yytext);}
"goto"          {printf("\t%-50s : Keyword\n", yytext);}
"break"         {printf("\t%-50s : Keyword\n", yytext);}
"continue"      {printf("\t%-50s : Keyword\n", yytext);}
"main"      {printf("\t%-50s : Keyword\n", yytext);}


 /* Constants */

[+/-]?[0][x|X]{hex}+              {printf("This is a hexadecimal Constan: %s\n",yytext);}
[+/-]?{digit}+                    {printf("This is an Integer Constant: %s\n",yytext);}
[+/-]?({digit}+)["."]({digit}+)   {printf("This is a Decimal Constnat: %s\n",yytext);}


[+/-]?[0][x|X]{hex}+              {printf("\t%-50s : Hexadecimal Constant\n", yytext);}
[+/-]?{digit}+                    {printf("\t%-50s : Integer Constant\n", yytext);}
[+/-]?({digit}+)["."]({digit}+)   {printf("\t%-50s : Decimal Constant\n", yytext);}

{identifier}    {if(strlen(yytext) <= 32)printf("\t%-50s : Identifier\n", yytext); else printf("Error %d: Identifier too long,must be between 1 to 32 characters", yylineno);}
{digit}+({letter}|_)+ {printf("Error %d: Illegal identifier format\n", yylineno);}
{whitespace}    ;

 /* Preprocessor Directives */

^"#include"                     {BEGIN PREPROCESSOR;}
<PREPROCESSOR>{whitespace}      ;
<PREPROCESSOR>"<"[^<>\n]*">"    {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"      {printf("\t%-50s : Preprocessor directive\n", yytext); BEGIN INITIAL;}
<PREPROCESSOR>"\n"              {printf("Error %d: Header format not allowed\n", yylineno); yylineno++; BEGIN INITIAL;}
<PREPROCESSOR>.                 {printf("Error %d: Header format not allowed\n", yylineno); BEGIN INITIAL;}

 /* Macropreprocessor Directives */

^"#define"                                        {BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace}                   ;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {printf("\t%-50s : Macropreprocessor directive\n", yytext); BEGIN INITIAL;}
<MACROPREPROCESSOR>\n                             {yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>.                              {printf("Error %d: Invalid definition\n", yylineno); BEGIN INITIAL;}

 /* Comments */

"/*"                                  {BEGIN COMMENT;}
<COMMENT>.|{whitespace}               ;

<COMMENT>\n                           {yylineno++;}
<COMMENT>"*/"                         {BEGIN INITIAL;}
<COMMENT>"/*"                         {printf("Error %d: Nested comments are invalid\n", yylineno);yyterminate();BEGIN INITIAL;}
<COMMENT><<EOF>>                      {printf("Error %d: Unterminated comments are invalid\n", yylineno); yyterminate();}
"//"                                  {BEGIN SLCOMMENT;}
<SLCOMMENT>.                          ;
<SLCOMMENT>\n                         {yylineno++; BEGIN INITIAL;}

 /* Operators */

"+"   {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"-"   {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"*"   {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"/"   {printf("\t%-50s : Arithmetic Operator\n", yytext);}
"="   {printf("\t%-50s : Assignment Operator\n", yytext);}
"--"  {printf("\t%-50s : Decrement Operator\n", yytext);}
"++"  {printf("\t%-50s : Increment Operator\n", yytext);}

">"  {printf("\t%-50s : Comparison Operator\n", yytext);}
"<"  {printf("\t%-50s : Comparison Operator\n", yytext);}
">=" {printf("\t%-50s : Comparison Operator\n", yytext);}
"<=" {printf("\t%-50s : Comparison Operator\n", yytext);}
"==" {printf("\t%-50s : Comparison Operator\n", yytext);}

"||" {printf("\t%-50s : Boolean Operator\n", yytext);}
"&&" {printf("\t%-50s : Boolean Operator\n", yytext);}
"!"  {printf("\t%-50s : Boolean Operator\n", yytext);}

 /* Strings and Characters */

\"[^\"\n]*$  {printf("Error %d: Illegally terminated string\n", yylineno); yyterminate();}

\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
    printf("\t%-50s : String\n", yytext);
  }
  else
    printf("\t%-50s : String\n", yytext);
}

\'[^\'\n]\' {printf("\t%-50s : Character\n", yytext);}

<COMMENT>\n                          	{yylineno++;}
<COMMENT>"*/"                        	{BEGIN INITIAL;}
<COMMENT>"/*"                        	{printf("Nested comments are not valid.\n");}
<COMMENT><<EOF>>                     	{printf(" Unterminated comment\n"); yyterminate();}
"//"        				                  {BEGIN SLCOMMENT;}
<SLCOMMENT>.                            ;
<SLCOMMENT>\n                           {yylineno++; BEGIN INITIAL;}


 /* Operators */

"+"   {printf("Arithmetic Operator: %s\n",yytext );}
"-"   {printf("Arithmetic Operator: %s\n",yytext );}
"*"   {printf("Arithmetic Operator: %s\n",yytext );}
"/"   {printf("Arithmetic Operator: %s\n",yytext );}
"="   {printf("Assignment Operator: %s\n",yytext );}
"--"  {printf("Decrement Operator: %s\n",yytext);}
"++"  {printf("Increment Operator: %s\n",yytext);}

 /* Comparison and boolean operators   */

">" {printf("Comparison Operator: %s\n",yytext );}
"<" {printf("Comparison Operator: %s\n",yytext );}
">=" {printf("Comparison Operator: %s\n",yytext );}
"<=" {printf("Comparison Operator: %s\n",yytext );}
"==" {printf("Comparison Operator: %s\n",yytext );}
"!=" {printf("Comparison Operator: %s\n",yytext );}

"||" {printf("Boolean Operator: %s\n",yytext );}
"&&" {printf("Boolean Operator: %s\n",yytext );}
"!"  {printf("Boolean Operator: %s\n",yytext );}

 /* Strings and Characters*/


\"[^\"\n]*$  {printf("Line: %d Illegaly terminated string: %s\n",yylineno,yytext );}

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was escaped */
    yymore();
    printf("String: %s\n",yytext );
  }
  else
  {
    printf("String: %s\n",yytext );
  }
 }




 /* Punctuators */
"[" {printf("Square Bracket: %s\n",yytext);}
"]" {printf("Square Bracket: %s\n",yytext);}
"{" {printf("Curly Bracket: %s\n",yytext);}
"}" {printf("Curly Bracket: %s\n",yytext);}
")" {printf("Curve Bracket: %s\n",yytext);}
"(" {printf("Curve Bracket: %s\n",yytext);}
"," {printf("Comma: %s\n",yytext);}
";" {printf("Delimeter: %s\n",yytext);}


"[" {printf("\t%-50s : Open Square Bracket\n", yytext);}
"]" {printf("\t%-50s : Closed Square Bracket\n", yytext);}
"{" {printf("\t%-50s : Open Curly Bracket\n", yytext);}
"}" {printf("\t%-50s : Closed Curly Bracket\n", yytext);}
"(" {printf("\t%-50s : Open Curve Bracket\n", yytext);}
")" {printf("\t%-50s : Closed Curve Bracket\n", yytext);}
"," {printf("\t%-50s : Comma\n", yytext);}
";" {printf("\t%-50s : Delimiter\n", yytext);}


.   {printf("Error %d: Illegal character\n", yylineno);}
"\n" {yylineno++;}

%%

int yywrap(){return 1;};

int main()
{
  extern FILE *yyin;
  yyin = fopen("test-case-strings.c","r");
  yylex();
  printf("Lexical analysis finished\n");
  return 0;
}
