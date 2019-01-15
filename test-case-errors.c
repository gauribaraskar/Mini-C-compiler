#include<stdio.h>
//Illegal header format 
#include 

int main(){
  //Illegal identifier
  int 2invalid;
  //Identifier too long
  int abcdefghijklmnopqrstuvwxyzabcdefgh;
  int x , y;
  //Illegeal character
  y = x $ x;
  /* Nested comments /*are not*/ allowed */
  return 0; 
}