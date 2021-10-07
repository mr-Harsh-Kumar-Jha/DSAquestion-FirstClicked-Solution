#include<stdio.h>
#include<string.h>

int main()
{
	char string[]="<H1>    Hy this Harsh    <H2>";
	parsar(string);
	printf("the parced string is ~~%s~~",string);
	return 0;
}
void parsar(char *string)
{
	int c,i;
	int index=0;
	for(i=0;i<strlen(string);i++)
	{

      	if(string[i]=='<')
	    {
	       c=0;
		   continue;	
    	}
    	else if(string[i]=='>')
	    {
		   c=1;
		   continue;
	    }  
	    if(c==1)
	    {
		   string[index]=string[i];
		   index++;
	    }
	}
	 string[index]='\0';
}           

