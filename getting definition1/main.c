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
long int loc=0;
double jwd,jwdmax=0;
/* if we put these outside the function we will get an error coz DEF_SIZE is a variable
char Match1[DEF_SIZE];
double jwd1=0.0;

char Match2[DEF_SIZE];
double jwd2=0.0;

char Match3[DEF_SIZE];
double jwd3=0.0;
*/
unsigned char Match[500];
int main()
{
	int z;
	for(z=0;z<500;z++)
	{
		Match[z]='\0';
	}
    unsigned char bufferAssist[1];
	char Match1[DEF_SIZE];
    double jwd1=0.0;

    char Match2[DEF_SIZE];
    double jwd2=0.0;

    char Match3[DEF_SIZE];
    double jwd3=0.0;

    printf("enter a word -> ");
    char ask[6];
    scanf("%s",ask);
    sourceMain = fopen("Dictionary.txt", "r");
    sourceAssist = fopen("Dictionary.txt", "r");    
    destination=fopen("destination.txt","w");
    printf("### 1");
    if (sourceMain)
    {
        while (!feof(sourceMain))
        {
        	int i,j,k,l,m,o,p,q;
        	char word[20];
        	for(p=0;p<20;p++)
        	{
        		word[p]='\0';
			}
        	/*for(o=0;o<1024;o++)
        	{
        		m=fread(bufferAssist,1,1,sourceAssist);
        		if(bufferAssist[0]=='\n')break;
			}
			BUFFER_MAIN_SIZE=o-1;*/
			printf("### 2");
        	unsigned char bufferMain[BUFFER_MAIN_SIZE];
            n = fread(bufferMain, 1, BUFFER_MAIN_SIZE, sourceMain);
            for(i=0;i<BUFFER_MAIN_SIZE;i++)
            {   
            	if(bufferMain[i]=='\n')
            	{
            		for(j=i+1,q=0;j<BUFFER_MAIN_SIZE;j++)
            		{
            			if(bufferMain[j]=='(')break;
            			else
						{
							if(bufferMain[j]!='"')
							{
								word[q]=bufferMain[j];
								q++;
						    }
					    }
					}
			printf("### 3");
				int q1;
				for(q1=0;q1<20;q1++)
				{
					if(word[q1]=='\0')break;
				}	
				unsigned char onlyWord[q1];
				for(q=0;q<q1;q++)
				{
					onlyWord[q]=word[q];
				}
				printf("### 4");
				fprintf(destination,"%s\t",word);
				jwd=jaro_winkler_distance(ask,onlyWord);
				if(jwd>THRESHOLD && jwd>jwdmax)
				{
					for(z=0;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
				}
				if(jwdmax<jwd)jwdmax=jwd;
				fprintf(destination,"%lf\n",jwd);
				}
            }
        }
    }
    printf("### 5");
    printf("%lf",jwdmax);
    printf("\n%s",Match);
    fclose(sourceMain);
    fclose(sourceAssist);
    fclose(destination);
    return 0;
}
