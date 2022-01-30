// tiime compllexity of this solution is O(n) and is one of the optimised solution

#include<stdio.h>

int main(){
   int arr[]={1,0};
   int size=sizeof(arr)/sizeof(arr[0]);
   int product_array[size];
   int temp2=1;
  int count=0;
   int temp=1;
   for(int i=0;i<size;i++){
             if(arr[i]==0){
                count=count+1;
            }
        }

   for(int i=0;i<size;i++){
      temp=temp*arr[i];
       if(arr[i]!=0 && count==1){

                temp2=temp2*arr[i];
            }
   }

    for(int i=0;i<size;i++)
    {
       if(arr[i]!=0)
          product_array[i]=temp/arr[i];
          else if(arr[i]==0 && count>1)
          product_array[i]=temp;
          else
          product_array[i]=temp2;  // this is the case for chacking if arr[i]==0 and count==1;

    }

    for(int i=0;i<size;i++)
    {
       printf("%d\n", product_array[i] );
    }
}