#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *Fpoint;
void wordcount(char *Filename)
{		
	int wordnumber=0;
	int flag=0;
	char c;
	if((Fpoint=fopen(Filename,"rb"))==NULL)
	{
	    printf("failed");
		exit(0);
	}
    while(!feof(Fpoint))
    {
	   c=fgetc(Fpoint);
	   if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
	   {
			  	   flag=1;
	   }
	  else if(flag)
	  {
				 	wordnumber++;
					flag=0;
	  }
	}

		fclose(Fpoint);
		printf("word number£º%d\n",wordnumber);
}
void charcount(char *Filename)
{	
	
	int charnumber=0;
	char ch;
	if((Fpoint=fopen(Filename,"rb"))==NULL)
	{
	    printf("failed\n");
		exit(0);
	}
	 while(!feof(Fpoint))
    {
	   ch=fgetc(Fpoint);
	   if(ch!='\n'&&ch!='\t'&&ch!=' ')
		{
			charnumber++;
		}

	}
		fclose(Fpoint);
		printf("char number£º%d\n",charnumber);
}					
int  main(int argc,char *argv[])
{
    if(!strcmp(argv[1],"-w"))
		wordcount(argv[2]);
	else if(!strcmp(argv[1],"-c"))
		charcount(argv[2]);
	return 0;
}
