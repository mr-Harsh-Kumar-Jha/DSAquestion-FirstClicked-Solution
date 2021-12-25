#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        int j;      10
        for(j=1; j<=n-i; j++)
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
