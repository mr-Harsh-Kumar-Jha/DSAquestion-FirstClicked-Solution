/* Write a C program to automate the process of computing Fibonacci sequence upto nth terms in particular , your program will do the following
1. Take from user the order K of generalized Fibonnaci sequence
2. Next , take all k base/initial terms from user and keep it an array
3. Then, take from user totsl number of terms (n) to be computed
4. compute the output

Sample input:
3
1 2 3
9

Sample Output:
1 2 3 6 11 20 37 68 125
*/
#include <stdio.h>

int main() {

    int N2;
    scanf("%d",&N2);
    int K[N2];
    int sum=0;
    for(int i=0;i<N2;i++){
        scanf("%d",&K[i]);
        sum=sum+K[i];
    }
    int N;
    scanf("%d",&N);
    for(int i=0;i<N2;i++){
        printf("%d ",K[i]);
    }
    int K2[N-N2];
    K2[0]=0;
    for(int i=0;i<N2;i++){
        K2[i+1]=K[i];

    }

    for(int i=N2;i<N;i++){
       sum=sum-K2[i-N2];
       K2[i+1]=sum;
       printf("%d ",sum);
       sum=sum+K2[i+1];
    }

    return 0;
}