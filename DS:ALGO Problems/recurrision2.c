#include<stdio.h>
void factorial(int,int);
void factorial(int e,int c)
{
	int d,i=1;
	if(c-1!=1)
	{
	   c=c*	(c-1);
	   printf("%d",c);
	   factorial(c-1);
	   
	}
	
}
int main()
{
	int n;
	printf("enter the no u want have factorial:\n");
	scanf("%d",&n);
	factorial(n);	
}
