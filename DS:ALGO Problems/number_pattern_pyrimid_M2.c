#include<stdio.h>

int main()
{
    int n,j,i;

    printf("Enter the size of pyrimid: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++){
          printf(" ");
        }
        for(j=1;j<=(2*i)-1;j++)
        {
            if(j%2==0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}
