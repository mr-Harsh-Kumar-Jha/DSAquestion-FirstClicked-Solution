#include<stdio.h>

int main(){
   int arr[]={10,5,7,2,11};
   int size=sizeof(arr)/sizeof(arr[0]);
   int product_array[size];

   int temp=1;
   for(int i=0;i<size;i++){
      temp=temp*arr[i];
   }

    for(int i=0;i<size;i++)
    {
       product_array[i]=temp/arr[i];
    }

    for(int i=0;i<size;i++)
    {
       printf("%d\n", product_array[i] );
    }
}