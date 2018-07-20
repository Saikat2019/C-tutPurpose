#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main()
{
   int num;
   FILE *fptr;
   fptr = fopen("data.txt","r");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   
   
   char data1[100000000];
   
   /*the size of the file data.txt is very large. we can not load the whole file in a buffer.
   that is why if we take data[10000000] instead of data[1000000] the programme will not work 
   properly.so we will have to take a different method to load and process the whole file 
   data.txt(size 5mb)*/  
   
   fgets (data1, 1000000, fptr);
   
   printf("%s",data1);
   
   fseek(fptr, 0L, SEEK_END);
 
   /*4912994*/
   long int res = ftell(fptr);
   
   fclose(fptr);
   
   printf("\n size = %ld",res);


   return 0;
}
