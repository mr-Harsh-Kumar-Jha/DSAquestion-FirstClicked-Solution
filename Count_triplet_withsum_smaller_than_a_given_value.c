#include<stdio.h>

void sort(int arr[],int size)
{
 int temp1;
 int k;
    for (int i=0;i<size;i++)
    {
        temp1=arr[i];
        k=i;
        for(int j=i-1;j>=0;j--)
        {
           if(arr[j]>temp1)
           {
              arr[k]=arr[j];
              k=j;
              
           }
        }
        arr[k]=temp1;
    }
}

void find(int arr[],int arr1[],int size,int sum,int data,int k,int j)
{
     if(k==3 && sum<data)
     {
         for(int m=0; m<3; m++)
       {
           //sort(arr1 , 4);
           printf("%d",arr1[m]);
           printf(" ");
       }
       printf("\n");
     }
     else if(k==3 && sum>=data){
         return;
     }
    for(int i=j;i<size;i++)
    {
       arr1[k]=arr[i];
       sum=sum+arr1[k];
       find(arr,arr1,size,sum,data,k+1,++j);
       sum=sum-arr1[k];
    }
}

int main()
{
    int arr[]={-2, 0, 1, 3};
    int size=sizeof(arr)/sizeof(int);
    sort(arr,size);
    int data=2;
    int sum=0;
    int k=0;
    int j=0;
    int arr1[3];
    find(arr,arr1,size,sum,data,k,j);

}