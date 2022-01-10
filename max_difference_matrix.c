//time complexity is O(n^4)  not an optimised solution , it's a brute force approach.

#include<stdio.h>
#include<limits.h>

void findMax(int arr[][5], int size){
    int i,j,k,l;
    int max=INT_MIN;
    int temp;
    for(i=0;i<size;i++)
    {
       for(j=0;j<size;j++)
       {
          for(k=i+1;k<size;k++)
          {
             for(l=j+1;l<size;l++)
             {
                temp=arr[k][l]-arr[i][j];
                if(temp>max){
                   max=temp;
                }
             }
          }
       }
    }
    printf("max difference= %d",max);
}

int main(){
   int arr[][5]= {{ 1, 2, -20, -4, -20 },
                 { -8, -3, 4, 2, 1 },
                 { 3, 8, 6, 1, 3 },
                 { -4, -1, 1, 7, -6 },
                 { 0, -4, 10, -5, 1 }};
   int size=5;
   findMax(arr,size);
}