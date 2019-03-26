#include <stdio.h>
 
int main () {

   int a = 10;
   while( a < 20 ) {
      a++;
		
      if( a > 15) {
         break;
      }
   }
 
   return 0;
}