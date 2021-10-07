#include<stdio.h>
int main()
{
	int a,b,i;
	printf("enter the no u want to have LCM \n");
	scanf("%d%d",&a,&b);
	
		for( i=1;i<=a*b;i++)
		{
			if(i%a==0&&i%b==0)
			{
				printf("\n your LCM is: %d\n",i);
				break;
			}	
		}

}
