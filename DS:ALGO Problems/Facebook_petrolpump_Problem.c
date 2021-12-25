#include<stdio.h>

int main()
{
    int petrol[50],distance[50];
    int i,n,j;
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

    j=0;
    for(i=0;i<n;i++)
    {
        if(petrol[i]+start<distance[i])
        {
            dif=dif+(petrol[i]-distance[i]);
            j=i+1;
        }
        else
        {
            start=start+petrol[i]-distance[i];
        }
    }
    if(start>=(-dif))
    {
         printf("%d",j+1);
    }
    else{
        printf("-1");
    }
}
