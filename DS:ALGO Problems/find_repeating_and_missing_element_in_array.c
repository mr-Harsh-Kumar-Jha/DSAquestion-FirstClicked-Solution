#include<stdio.h>
void find(int arr[],int size)
{
    int arr2[size];
    for(int i=0;i<size;i++)
    {
        arr2[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        arr2[arr[i]]=arr2[arr[i]]+1;
    }
    for(int i=1;i<size;i++)
    {
        if(arr2[i]>1)
          printf("repeated no=%d\n",i);
        if(arr2[i]<1)
          printf("no. not mentioned=%d\n",i);
    }
}
int main()
{
    int arr[]={1,2,3,4,7,5,6};//given array is a container of n natural no. where one among all natural no is absebt and one is repeated 
    int size=sizeof(arr)/sizeof(int);
    find(arr,size);
}