#include <stdio.h>
#include "jaro_winkler_dist.h"

#define THRESHOLD 0.9

int BUFFER_SIZE = 1024;
FILE *source;
FILE *destination;
int n;
int count = 0;
int written = 0;
long int size=0;
long int nol=0;

int main()
{
    unsigned char buffer[BUFFER_SIZE];
    printf("enter a word -> ");
    char ask[5];
    scanf("%s",ask);
    source = fopen("A.txt", "r");
    destination=fopen("destination.txt","w");

    if (source)
    {
        while (!feof(source))
        {
        	int i,j,k,l,m;
        	char word[20];
            n = fread(buffer, 1, BUFFER_SIZE, source);
            for(i=0;i<1024;i++)
            {
            	if(buffer[i]=='\n')
            	{
            		for(j=i+1;j<1024;j++)
            		{
            			if(buffer[j]=='(')break;
            			else
						{
						 word[j-i-1]=buffer[j];
						 if(buffer[j]==' ') 
						 {
						 	k=j;
						 	for(j=j-i;j<20;j++) /*if the size of the word is less than 20 then we are filling the rest of the word with null character '\0'*/
						 	{
						 		word[j]='\0';
							}
							break;
						 }
					    }
					}
				char onlyWord[k];
				for(l=0;l<k;l++)
				{
					onlyWord[l]=word[l];
				}	
				double jwd=jaro_winkler_distance(ask,onlyWord);
				fprintf(destination,"%s\t",onlyWord);
				fprintf(destination,"%lf\n",jwd);
				
				}
            }
        }
    }

    fclose(source);
    fclose(destination);
    return 0;
}
