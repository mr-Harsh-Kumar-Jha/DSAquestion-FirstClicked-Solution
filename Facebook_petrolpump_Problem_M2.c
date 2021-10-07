#include<stdio.h>

int main()
{
    int petrol[50],distance[50];
    int i,n;
    int start=0,dif=0;

    printf("Enter no of petrolpumps: ");
    scanf("%d",&n);

    printf("Enter the capacity of petrolpumps:\n ");
    for(i=0; i<n; i++)
    {
        printf("Capacity[%d]: ",i+1);
        scanf("%d",&petrol[i]);
    }

    printf("Enter the distance between petrolpumps:\n ");
    for(i=0; i<n; i++)
    {
        printf("Distance[%d]: ",i+1);
        scanf("%d",&distance[i]);
    }

    int sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+petrol[i]-distance[i];
        if(sum<0)
        {
            start=i+1;
            dif+=sum;
            sum=0;
        }
    }
    if(sum+dif>=0)
    {
        printf("%d",start+1);
    }
    else
    {
        printf("-1");
    }
}
