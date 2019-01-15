/* This file tests the detection of allowed keywords , identifiers and other tokens such as punctuators , operators */

//Identifies prepocessor directives
#include<stdio.h>
#include "stdlib.h"
//Identifies macro preprocessor directives
#define MAX 100

int main(){

	//Identifies keywords int , long , char , if , else and operators
	int a;
	long int b;
	char c;
	int e,f,g;

	//Identifies constants
	int f = 0xAB;
	c = 'A';
	f = 1;
	g = -5;

	//Identifies arithmetic operators
	e = f+g;
	e = f-g;

	// Identifies conditions
	if(c=='A')
		a = 10;
	else
		a = 30;

	// Identifies loops

	for ( a = 0; a<3; a++){
	}

	return 0;
}

