#include <stdio.h>
#include "jaro_winkler_dist.h"

#define THRESHOLD 0.6

int BUFFER_MAIN_SIZE = 200;/*if we keep this buffer size large then the program may hang*/
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

unsigned char Match1[500];
double jwd1=0;
unsigned char Match2[500];
double jwd2=0;
unsigned char Match3[500];
double jwd3=0;
unsigned char Match4[500];
double jwd4=0;
unsigned char Match5[500];
double jwd5=0;
double mod(double val)
{
	if(val>0.0)return val;
	else return (val*-1);
}
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
    
    printf("Enter the size of the word -> ");
    int size;
    scanf("%d",&size);

    printf("enter a word -> ");
    char ask[size];
    scanf("%s",ask);
    sourceMain = fopen("Dictionary.txt", "r");
    sourceAssist = fopen("Dictionary.txt", "r");    
    destination=fopen("destination.txt","w");
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
        	unsigned char bufferMain[BUFFER_MAIN_SIZE];
            n = fread(bufferMain, 1, BUFFER_MAIN_SIZE, sourceMain);
            for(i=0;i<BUFFER_MAIN_SIZE;i++)
            {   
            	if(bufferMain[i]=='\n')
            	{
            		for(j=i+1,q=0;j<BUFFER_MAIN_SIZE;j++)
            		{
            			if(bufferMain[j]=='(' ||bufferMain[j-1]==' ')
						{
						    break;
						}
            			else
						{
							if(bufferMain[j]!='"')
							{
								word[q]=bufferMain[j];
								q++;
						    }
					    }
					}
				int q1;                                   /*krystall Ball Mud Ghostb*/
				for(q1=0;q1<20;q1++)
				{
					if(word[q1]=='\0')break;
				}	
				unsigned char onlyWord[q1];
				for(q=0;q<q1;q++)
				{
					onlyWord[q]=word[q];
				}
				
				jwd=jaro_winkler_distance(ask,onlyWord);
				int x=0;
				/*if(x==0&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match1[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match1[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}
				if(x==1&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match2[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match2[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}
                if(x==2&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match3[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match3[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}
				if(x==3&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match3[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match3[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}
				if(x==4&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match4[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match4[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}
				if(x==5&&mod(jwd-jwdmax)<0.03)
				{
					for(q=0;q<q1;q++)
					{
						Match5[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match5[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
					x++;
				}*/
				if(jwd>THRESHOLD && jwd>jwdmax)
				{
					for(q=0;q<q1;q++)
					{
						Match[q]=onlyWord[q];
					}
					for(z=q;j<BUFFER_MAIN_SIZE;j++,z++)
					{
					  	Match[z]=bufferMain[j];
					  	if(bufferMain[j]=='\n')break;
					}
				}
				if(jwdmax<jwd)jwdmax=jwd;
				
				}
            }
        }
    }
    
    printf("\n%s",Match);
    fprintf(destination,"%s",Match);
    /*printf("\n%s",Match1);
    printf("\n%s",Match2);
    printf("\n%s",Match3);
    printf("\n%s",Match4);
    printf("\n%s",Match5);*/

    fclose(sourceMain);
    fclose(sourceAssist);
    fclose(destination);

    return 0;
}
