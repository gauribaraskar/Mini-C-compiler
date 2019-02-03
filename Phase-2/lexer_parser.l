
%{
    #include<stdio.h>
    #include<stdlib.h>

    int ErrFlag = 0;
    

    #include "y.tab.h"
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

"int"                               {return INT;}
"short"                             {return SHORT;}
"long"                              {return LONG;}
"char"                              {return CHAR;}
"signed"                            {return SIGNED;}
"unsigned"                          {return UNSIGNED;}
"void"                              {return VOID;}
"if"                                {return IF;}
"else"                              {return ELSE;}
"for"                               {return FOR;}
"do"                                {return DO;}
"while"                             {return WHILE;}
"goto"                              {return GOTO;}
"break"                             {return BREAK;}
"continue"                          {return CONTINUE;}
"main"                              {return MAIN;}
"return"                            {return RETURN;}


 /* Constants */

[+/-]?[0][x|X]{hex}+                {printf("\t%-50s : Hexadecimal Constant\n", yytext); return HEX_CONSTANT;}
[+/-]?{digit}+                      {printf("\t%-50s : Integer Constant\n", yytext); return INT_CONSTANT;}
[+/-]?({digit}*)["."]({digit}+)     {printf("\t%-50s : Decimal Constant\n", yytext); return DEC_CONSTANT;}
[+/-]?({digit}+)["."]({digit}*)     {printf("\t%-50s : Decimal Constant\n", yytext); return DEC_CONSTANT;}

{identifier} {
  if(strlen(yytext) <= 32)
    {
      printf("\t%-50s : Identifier\n", yytext);
      return IDENTIFIER;
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

"+"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext); return ADD;}
"-"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext); return SUBTRACT;}
"*"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext); return MULTIPLY;}
"/"                                 {printf("\t%-50s : Arithmetic Operator\n", yytext); return DIVIDE;}
"="                                 {printf("\t%-50s : Assignment Operator\n", yytext); return ASSIGN;}
"--"                                {printf("\t%-50s : Decrement Operator\n", yytext); return DECREMENT;}
"++"                                {printf("\t%-50s : Increment Operator\n", yytext); return INCREMENT;}

">"                                 {printf("\t%-50s : Comparison Operator\n", yytext); return GREATER_THAN;}
"<"                                 {printf("\t%-50s : Comparison Operator\n", yytext); return LESSER_THAN;}
">="                                {printf("\t%-50s : Comparison Operator\n", yytext); return GR_EQ;}
"<="                                {printf("\t%-50s : Comparison Operator\n", yytext); return LESS_EQ;}
"=="                                {printf("\t%-50s : Comparison Operator\n", yytext); return EQUAL;}

"||"                                {printf("\t%-50s : Boolean Operator\n", yytext); return LG_OR;}
"&&"                                {printf("\t%-50s : Boolean Operator\n", yytext); return LG_AND;}
"!"                                 {printf("\t%-50s : Boolean Operator\n", yytext); return NOT;}
"!="                                {printf("\t%-50s : Boolean Operator\n", yytext); NOT_EQ;}


 /* Strings and Characters */

\"[^\"\n]*$                         {printf("Error %d: Illegally terminated string\n", yylineno);ErrFlag=1; yyterminate();}
\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
  }
  else
  {
    
    printf("\t%-50s : String\n", yytext);
    return STRING;
  }
}

\'[^\'\n]\'                         {printf("\t%-50s : Character\n", yytext);}


 /* Punctuators */


"\n"                                {yylineno++;}
.                                   {printf("Error %d: Illegal character\n", yylineno);ErrFlag=1;}

%%


