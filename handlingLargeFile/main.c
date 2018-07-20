#include <stdio.h>

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

    source = fopen("Oxford_Dictionary.txt", "r");
    destination=fopen("des.txt","a");

    if (source)
    {
        while (!feof(source))
        {
        	int i,j;
        	char word[20];
            n = fread(buffer, 1, BUFFER_SIZE, source);
            for(i=0;i<BUFFER_SIZE;i++)
            {
            	if(buffer[i]=='\n')
            	{
            	    for(j=i+1;;j++)
					{
						word[j-i-1]=buffer[j];
						if(j>BUFFER_SIZE)break;
						else if (buffer[j]==' ')break;
						else if (buffer[j]=='\n')break;
						else continue;
					}
					printf("%ld -> %s\n",nol,word);	
					fprintf(destination,"%s",word);
					char enter[1]="\n";
					fprintf(destination,"%s",enter);
					nol++;	
				}
		    }
            count += n;
            size+=n;
        }
    }

    fclose(source);
    fclose(destination);
    printf("\n%ld",size);
    printf("\nno of lines = %ld",nol);
    return 0;
}
