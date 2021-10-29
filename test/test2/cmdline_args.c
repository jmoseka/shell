#include <stdio.h>
/**
 * main - Handle command lines with arguments
 */

void main(int argc, char *argv[] )
{
   if(argc < 2){  
      printf(" ");  
   }  
   else{  
      printf("%s", argv[1]);  
   }  

}
