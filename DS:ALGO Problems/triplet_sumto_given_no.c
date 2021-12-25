#include<stdio.h>
int count=0;

void recurse (int a[],int arr[],int size, int j, int k, int data,int sum)
{
    if(k==3 && sum==data)
    {
        count+=1;
        return;
    }
    if((k==3 && sum!=data)||(sum>data))
        return;
    // printf("u=%d\t",j);

    for(int i=j;i<=size-1;i++)
    {
      //  printf("i=%d",j);
        arr[k]=a[i];
      //  printf("k=%d\t",arr[k]);
        sum=sum+a[i];
      //  printf("a=%d\t",sum);
        recurse(a, arr, size, ++j, k+1, data, sum);
        sum=sum-a[i];
      //  printf("j=%d",i);
      //  printf("c=%d\n",sum);
    }
}
int main() {
    int a[]={1, 5,7,1,5};
    int arr[3];
    int size=sizeof(a)/sizeof(int);
    int j=0;
    int k=0;
    int data=7;
    recurse(a, arr, size, j, k, data,0);
    printf("%d",count);
}
