#include<stdio.h>
int main()
{
	int n,i,j;
	printf("enter the no of column you want to have pattern ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(2*n)-1;j++)
		{
			if(j<=n-i)
			{
				printf(" ");
			}
			else if(j<n+i&&j>n-i)
			{
				printf("*");
			}
		}
		printf("\n");
	}
}


