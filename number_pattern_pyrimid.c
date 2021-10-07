/*printing         *
                  * *
                 * * *     */
#include<stdio.h>
int main()
{
    int i,j,n;

    printf("enter the sries no you want to print :");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
           printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
