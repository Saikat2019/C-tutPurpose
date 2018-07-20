#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

size_t strFun(char string[])
   {
   	printf("\nprinting string from the function %s\n",string);
   	return strlen(string);
   }

int main(int argc, char *argv[]) {	
	char str[max_size];
	int i=0;
	printf("string manipulation using getchar()\n");
	char ch;
	while(ch!='\n') /*until we press enter*/
	{
		ch=getchar();
		str[i]=ch;
		i++;
	}
	str[i]='\0';/*inserting null character at the end*/
	printf("printing the string %s",str);/*no need to put '[]' here*/
	
	printf("\nnow string manipulation using gets(str1)\n");
	
	gets(str);
	printf("printing the string using puts(str)\n");
	puts(str);
	printf("printing the string using printf\n");
	printf("%s",str);
	
	printf("\npassing string to functions which prints the string and returns it's size'\n");
	int size=strFun(str);
	printf("size of the string is %d",size);
	
	return 0;
}
