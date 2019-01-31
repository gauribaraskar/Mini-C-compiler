%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "tables.h"
%}

%union{
	int valInt;
	char *str;
	entry *valEntry;
	double valDouble;
}

%token <valEntry> IDENTIFIER
%token <valDouble> DEC_CONSTANT HEX_CONSTANT
%token <valEntry> STRING
// Keywords
%token IF ELSE WHILE FOR DO WHILE BREAK CONTINUE VOID GOTO RETURN 
// Data types
%token INT SHORT LONG CHAR SIGNED UNSIGNED
