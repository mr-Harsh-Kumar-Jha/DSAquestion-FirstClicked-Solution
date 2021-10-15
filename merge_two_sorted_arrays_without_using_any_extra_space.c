#include<stdio.h>

void merge(int arr1[],int size1,int arr2[],int size2)
{
    int i=0;
    int j=0;
    while(i!=size1 && j!=size2)
    {
        if(arr1[i]>arr2[j])
        {
           printf("%d",arr2[j]);
           j++;
        }
        else
        {
           printf("%d",arr1[i]);
           i++;
        }
        printf(" ");
    }
    if(i==size1)
    {
       for(;j<size2;j++)
       {
          printf("%d",arr2[j]);
          printf(" ");
       }
    }
    else{
       for(;i<size1;i++)
       {
          printf("%d",arr1[i]);
          printf(" ");
       }
     }
}

int main()
{
     int arr1[]={1, 3, 5, 7,10};
     int arr2[]={0, 2, 6, 8, 9};

     int size1=sizeof(arr1)/sizeof(int);
     int size2=sizeof(arr2)/sizeof(int);

     merge(arr1,size1,arr2,size2);
}