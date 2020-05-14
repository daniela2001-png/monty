#include "monty.h"

int main () {
   FILE *fp;
   int c;
  
   fp = fopen("001.m","r");

   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   
   return(0);
}