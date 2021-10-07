#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the no of column you want to have pattern ");
	sacnf("%d",n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(j<=n-i)
			{
				printf(" ");
			}
			if(j<n+i&&j>n-i)
			{
				printf("*");
			}
		}
	}
}


