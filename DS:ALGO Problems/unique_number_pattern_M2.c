/*output
    12345
    12 45
    1   1
*/

#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the size of column: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2*n-1;j++)
        {
            if((j<=n-i+1) || (j>=n+i-1))
            {
                printf("%d",j);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
