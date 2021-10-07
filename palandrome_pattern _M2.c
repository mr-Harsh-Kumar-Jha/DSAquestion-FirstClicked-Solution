#include<stdio.h>
int main()
{
    int i,n,j,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        /* k=i;
        for(j=1;j<n-i;j++)
        {
            printf(" ");
        }
        for(j=n; j<=i; j++)
        {
           printf("%d",k--);
        }
        for(j=n-1;j<=1;j++)
        {
            printf("%d",k--);
        } */
        for(j=1;j<n-i;j++)
        {
            printf(" ");
        }
        int k=i;
        for(j=n-i+1; j<=n; j++)
        {
            printf("%d",k--);
        }
        k=2;
        for(j=n+1; j<=n+i-1; j++)
        {
            printf("%d",k++);
        }
        printf("\n");
    }
}
