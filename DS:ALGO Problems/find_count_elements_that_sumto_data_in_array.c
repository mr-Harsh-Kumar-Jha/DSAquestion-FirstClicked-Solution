#include<stdio.h>
int count=0;
void countplease(int arr[],int N,int data,int sum,int i)
{
    if (sum==data)
    {
        count=count+1;
        return;
    }
    if(sum>data)
    {
        return;
    }
    for(i;i<N;i++)
    {
          sum=sum+arr[i];

          countplease(arr,N,data,sum,i+1);

          sum=sum-arr[i];
    }

}

int main()
{
    int arr[]={1,3,5,2,1};
    int N=sizeof(arr)/sizeof(int);
    int sum=0;
    int data=10;
    countplease(arr,N,data,sum,0);
    printf("%d",count);

}

