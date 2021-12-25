//fibonacci series using recurrision.

#include<stdio.h>

int fib(int n)
{
    if(n==0 ||  n==1){
        return n;
    }

    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    printf("Enter the no you want to have fibonacci series: ");
    scanf("%d",&n);
    printf("your fibonacci series is: %d",fib(n));
}
