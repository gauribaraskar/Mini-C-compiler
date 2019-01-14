%{
    #include<stdio.h>
    #include<stdlib.h>
%}

 /* Declarations */

letter [a-zA-Z]
digit [0-9]
whitespace [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}


 /* States */

%x PREPROCESSOR
%x MACROPREPROCESSOR
%x COMMENT


%%

 /* Keywords */

"int" 					{printf("Keyword: %s",yytext);}
"short" 				{printf("Keyword: %s",yytext);}
"long" 					{printf("Keyword: %s",yytext);}
"char" 					{printf("Keyword: %s",yytext);}
"signed" 				{printf("Keyword: %s",yytext);}
"unsigned" 				{printf("Keyword: %s",yytext);}
"void" 					{printf("Keyword: %s",yytext);}
"if" 					{printf("Keyword: %s",yytext);}
"else" 					{printf("Keyword: %s",yytext);}
"for" 					{printf("Keyword: %s",yytext);}
"do" 					{printf("Keyword: %s",yytext);}
"while" 				{printf("Keyword: %s",yytext);}
"goto" 					{printf("Keyword: %s",yytext);}
"break" 				{printf("Keyword: %s",yytext);}
"continue" 				{printf("Keyword: %s",yytext);}
{identifier} 				{printf("Identifier: %s\n",yytext);}
{whitespace} 				;

 /* Preprocessor Directives */

^"#include" 				{BEGIN PREPROCESSOR;}
<PREPROCESSOR>"<"[^<>\n]*">" 		{printf("Preprocessor directive: %s\n",yytext);BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\" 		{printf("Preprocessor directive: %s\n",yytext);}
<PREPROCESSOR>{whitespace} 		;
<PREPROCESSOR>"\n" 			{printf("This header format isn't allowed");yylineno++; BEGIN INITIAL;} 
<PREPROCESSOR>. 			{printf("This header format isn't allowed\n Line Number: %d",yylineno); BEGIN INITIAL;}

 /* Macropreprocessor Directives */

^"#define" 				{BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace} 	;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {printf("MACROPREPROCESSOR DIRECTIVE %s\n",yytext); BEGIN INITIAL;}
<MACROPREPROCESSOR>\n 			{yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>. 			{printf("Invalid Definition %d\n",yylineno); BEGIN INITIAL;}


"/*"                              	{ BEGIN COMMENT;}
<COMMENT>.|{whitespace}                 ;
<COMMENT>\n                          	{printf("\nComment: %s",yytext);yylineno++;}
<COMMENT>"*/"                        	{BEGIN INITIAL;}
<COMMENT>"/*"                        	{printf("Nested comments are not valid.\n");}
<COMMENT><<EOF>>                     	{printf(" Unterminated comment\n"); yyterminate();}
"//".*        				{printf("\nComment: %s\n",yytext);}

%%


int yywrap(){return 1;};

int main()
{
  extern FILE *yyin;
  yyin = fopen("2.c","r");
  yylex();
  printf("Lexical analysis Finished\n");
  return 0;
}
