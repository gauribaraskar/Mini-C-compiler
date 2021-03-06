 /* This file describes the rules for the lexer */
%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<limits.h>
    int ErrFlag = 0;

    extern int is_declaration;
    extern int is_param;

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
"void"                              {return VOID;}
"if"                                {return IF;}
"else"                              {return ELSE;}
"for"                               {return FOR;}
"do"                                {return DO;}
"while"                             {return WHILE;}
"goto"                              {return GOTO;}
"break"                             {return BREAK;}
"continue"                          {return CONTINUE;}
"return"                            {return RETURN;}
"float"                             {return FLOAT;}




 /* Constants */

[0][x|X]{hex}+                      {yylval.tbEntry = InsertEntry(ConstantTable, yytext , (int)strtol(yytext, NULL, 16),"HEX",yylineno,0);return HEX_CONSTANT;}
{digit}+                      {yylval.tbEntry = InsertEntry(ConstantTable, yytext , (int) atoi(yytext),"INT",yylineno,0);return INT_CONSTANT;}
({digit}*)["."]({digit}+)     {yylval.tbEntry = InsertEntry(ConstantTable, yytext , atof(yytext),"FLOAT",yylineno,0);return DEC_CONSTANT;}
({digit}+)["."]({digit}*)     {yylval.tbEntry = InsertEntry(ConstantTable, yytext , atof(yytext),"FLOAT",yylineno,0);return DEC_CONSTANT;}

{identifier} {
  if(strlen(yytext) <= 32)
    {
      yylval.str = yytext;
      if(is_declaration)
      {
        int nesting;
        if(is_param)
        {
          is_param = 0;
          nesting = curr_nest_level + 1;
        }
        else
        {
          nesting = curr_nest_level;
        }
        yylval.tbEntry = InsertEntry(SymbolTable,yytext,INT_MAX,curr_data_type,yylineno,nesting);
      }
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
<PREPROCESSOR>"<"[^<>\n]*">"        {BEGIN INITIAL;}
<PREPROCESSOR>\"[^<>\n]*\"          {BEGIN INITIAL;}
<PREPROCESSOR>"\n"                  { yylineno++; BEGIN INITIAL; ErrFlag=1;}
<PREPROCESSOR>.                     {yyerror("Improper Header");}


 /* Macropreprocessor Directives */

^"#define"                                        {BEGIN MACROPREPROCESSOR;}
<MACROPREPROCESSOR>{whitespace}                   ;
<MACROPREPROCESSOR>({letter})({letter}|{digit})*  {BEGIN INITIAL;}
<MACROPREPROCESSOR>\n                             {yylineno++; BEGIN INITIAL;}
<MACROPREPROCESSOR>.                              {BEGIN INITIAL;ErrFlag=1;}


 /* Comments */

"/*"                                {BEGIN COMMENT;}
<COMMENT>.|{whitespace}             ;
<COMMENT>\n                         {yylineno++;}
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {yyerror("Improper Comment");yyterminate();}
<COMMENT><<EOF>>                    {yyerror("Improper Comment");yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {yylineno++; BEGIN INITIAL;}


 /* Operators */

"+"                                 {return ADD;}
"-"                                 {return SUBTRACT;}
"*"                                 {return MULTIPLY;}
"/"                                 {return DIVIDE;}
"%"                                 {return MOD;}
"="                                 {return ASSIGN;}
"--"                                {return DECREMENT;}
"++"                                {return INCREMENT;}

"+="                                {return ADD_ASSIGN;}
"-="                                {return SUB_ASSIGN;}
"*="                                {return MUL_ASSIGN;}
"/="                                {return DIV_ASSIGN;}
"%="                                {return MOD_ASSIGN;}

">"                                 {return GREATER_THAN;}
"<"                                 {return LESSER_THAN;}
">="                                {return GREATER_EQ;}
"<="                                {return LESS_EQ;}
"=="                                {return EQUAL;}

"||"                                {return LG_OR;}
"&&"                                {return LG_AND;}
"!"                                 {return NOT;}
"!="                                {return NOT_EQ;}


 /* Strings and Characters */

\"[^\"\n]*$                         {ErrFlag=1; yyterminate();}
\"[^\"\n]*\" {
  if(yytext[yyleng-2]=='\\') {
    yyless(yyleng-1);
    yymore();
  }
  else
  {
    yylval.tbEntry = InsertEntry(ConstantTable,yytext,yylval.dval,"CHAR",yylineno,0);
    return STRING;
  }
}

\'[^\'\n]\'                         { yylval.tbEntry = InsertEntry(ConstantTable,yytext,yylval.dval,"CHAR",yylineno,0); return STRING;}


 /* Punctuators */


"\n"                                {yylineno++;}
.                                   {return yytext[0];}

%%

