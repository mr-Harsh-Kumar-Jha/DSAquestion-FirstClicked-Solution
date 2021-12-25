#include<stdio.h>

int sortcheck(int arr[],int n)
{
    if(n<=1){
        return 1;
    }
   if(arr[n-1]>=arr[n-2]){
       return (sortcheck(arr,n-1));
   }
    return 0;
}

int main()
{
    int arr[]={1,2,3,4,6,6};
    int n=6,sort;
    sort=sortcheck(arr,n);
    if(sort==1)
    {
        printf("Array is sorted.\n");
    }
    else{
        printf("Array is not sorted.\n");
    }
}
