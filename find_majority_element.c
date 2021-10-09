#include<stdio.h>
void find(int arr[],int size)
{
    int arr2[size],count=0;
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
        if(arr2[i]>=(size/2))
        {
            count=count+1;
            printf("repeated no=%d\n",i);
        }
    }
    if(count==0)
    {
        printf("no element is present whose presence is greater than n/2");
    }

}
int main()
{
    int arr[]={1,3,3,3,4,7,5,3};//given array is a container of n natural no. where one among all natural no is absebt and one is repeated 
    int size=sizeof(arr)/sizeof(int);
    find(arr,size);
}