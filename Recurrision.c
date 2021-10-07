#include<stdio.h>
void odd(int,int);
void odd(int b,int c)
{
	if(b>=c)
	{
		return ;
	}
	else if(b%2!=0)
	{
		printf("%d\n",b);
        odd(b+1,c);
	}
	else
	{
		odd(b+1,c);
	}
}
int main()
{
	int a=1,n;
	printf("enter the no till which u want to print the odd no:\n");
	scanf("%d",&n);
	odd(a,n);	
}
