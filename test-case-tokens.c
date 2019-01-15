/* This file tests the detection of allowed keywords , identifiers and other tokens such as punctuators , operators */

// Should detect prepocessor directives
#include<stdio.h>
#include "stdlib.h"

// Should detect macro preprocessor directives
#define MAX 100


int main(){

	// Identifying keywords int , long , char , if , else and operators
	int a ;
	long int b;
	char c;
	const int f = 0xAB;
	c = 'A';
	if(c=='A')
		a = 10;
	else
		a = 30;

	int 2tf;

	

	return 0;
}

