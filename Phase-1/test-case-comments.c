/* The lexical analyser should remove all the valid comments and throw an exception for all the invalid comments */

#include<stdio.h>

int main(){

	// Single line comment

	/* Single line comment with different beginning */

	/* Multi-line comment

	should be removed by lex */

	/* Nested comments are /* not */ allowed */

  return 0;

}
