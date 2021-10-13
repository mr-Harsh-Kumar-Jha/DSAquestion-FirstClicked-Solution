//method 1 :- to directly traverse mainntaining the diff btw current no. and no. after current to be <= max diff.

//method 2:
#include<stdio.h>
#include<stdlib.h>
int max(int a, int b)
{
    if(a>b)
    {
       return a;
    }
    else{
      return b;
    }
}
void searching(int arr[] , int size, int data, int diff)
{
    int i=0;
    while(i<size)
    {
         if(arr[i]==data)
         {
           printf("%d\t",i);
           return;
         }
         if( abs(arr[i+1]-arr[i]) > diff )
         {
            printf("wrong array input.");
            return;
         }

         i=i + max(1 , abs((arr[i]-data)/diff));
    }
}

int main()
{
    int arr[]={2,1,5,7,7,6};
    int size=sizeof(arr)/sizeof(int);
    int data=6;
    int diff=2;
    searching(arr,size,data,diff) ;
}