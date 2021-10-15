#include<stdio.h>

void solution(int arr[],int size)
{
    int i,j,max=0,sum=0;
    for (i=0;i<2;i++)
    {
     sum=0;
       for(j=i;j<size;)
       {
             sum = sum + arr[j];
             j=j+2;
       }
       if(sum > max)
       {
           max=sum;
       }
    }
    printf("%d",max);
}


int main()
{
   int arr[]={1,2,3};
   int size=sizeof(arr)/sizeof(int);

   solution(arr,size);
}