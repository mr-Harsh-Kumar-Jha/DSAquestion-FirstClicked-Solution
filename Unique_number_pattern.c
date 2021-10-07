/*      12345
        12 45
        1   5
*/

#include<stdio.h>

int main()
{
    int i,j,n;
    printf("Enter size of column: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            printf("%d",j);
        }
        for( j=n-i+2;j<=2*n-1;j++) //instead of n-i+2 we can also leave it a blank.//
        {
            if(j>=n+i-1){
               printf("%d",j);
            }
            else
               printf(" ");
        }
        printf("\n");
    }
}
