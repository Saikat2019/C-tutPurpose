#include <stdio.h>
#include "jaro_winkler_dist.h"

#define THRESHOLD 0.6

int BUFFER_MAIN_SIZE = 100;/*if we keep this buffer size large then the program may hang*/
int BUFFER_ASSIST_SIZE=100;
int DEF_SIZE=50;
FILE *sourceMain;
FILE *sourceAssist;
FILE *destination;
int n;
int count = 0;
int written = 0;
long int size=0;
long int nol=0;

/* if we put these outside the function we will get an error coz DEF_SIZE is a variable
char Match1[DEF_SIZE];
double jwd1=0.0;

char Match2[DEF_SIZE];
double jwd2=0.0;

char Match3[DEF_SIZE];
double jwd3=0.0;
*/
int main()
{
    
    
	char Match1[DEF_SIZE];
    double jwd1=0.0;

    char Match2[DEF_SIZE];
    double jwd2=0.0;

    char Match3[DEF_SIZE];
    double jwd3=0.0;

    printf("enter a word -> ");
    char ask[7];
    scanf("%s",ask);
    sourceMain = fopen("A.txt", "r");
    sourceAssist = fopen("A.txt", "r");    
    destination=fopen("destination.txt","w");

    if (sourceMain)
    {
        while (!feof(sourceMain))
        {
        	int i,j,k,l,m,o;
        	char word[20];
        	for(o=0;o<BUFFER_ASSIST_SIZE;o++)
        	{
			}
        	char bufferMain[BUFFER_MAIN_SIZE];
            n = fread(bufferMain, 1, BUFFER_MAIN_SIZE, sourceMain);
            for(i=0;i<BUFFER_MAIN_SIZE;i++)
            {
            	if(bufferMain[i]=='\n')
            	{
            		for(j=i+1;j<BUFFER_MAIN_SIZE;j++)
            		{
            			if(bufferMain[j]=='(')break;
            			else
						{
						 word[j-i-1]=bufferMain[j];
						 if(bufferMain[j]==' ') 
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
				if(jwd>THRESHOLD)
				{
					if(jwd>jwd1)
					{
						for(m=i;m<i+DEF_SIZE;m++)
						{
							Match1[m]=bufferMain[m];
							if(bufferMain[m]=='\n')break;
							if(m>BUFFER_MAIN_SIZE-1)break;
						}
						break;
					}
				}
				fprintf(destination,"%s\t",onlyWord);
				fprintf(destination,"%lf\n",jwd);
				}
            }
        }
        printf("%s",Match1);
    }
    
    fclose(sourceMain);
    fclose(sourceAssist);
    fclose(destination);
    return 0;
}
