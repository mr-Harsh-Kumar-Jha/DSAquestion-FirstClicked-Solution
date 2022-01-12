// Very great optimised solution O(1)

#include <stdio.h>
#include<limits.h>
#define R 5
#define C 5

void Find_kth_small(int arr[][C],int term_no){
    int i, j;
    i=(term_no-1)%R;
    j=(term_no-1)/R;
    int temp=arr[i][j];
    int min=INT_MAX;
    if(i-1>=0 && j+1<C){
       printf("a\n");
    for(int k=i-1;k<i;k++)
    {
       for(int l=j+1;i<C;i++)
       {
          if(temp>arr[k][l])
          {
             min=arr[k][l];
             temp=min;
          }
          else
           min=temp;
       }
    }
    }
     else if(j+1==C && i+1<R && j-1>0){
       printf("a\n");
       for(int k=i+1;k<R;k++)
       {
          for(int l=j-1;l<j;l++)
          {
             if(temp<arr[k][l])
             {
                min=arr[k][l];
                temp=min;
             }
             else
             min=temp;
          }
       }
    }
    else{
        printf("b\n");
      min=temp;
    }


    printf("%d",min);

}

int main() {

   int arr[][C]={{7 ,17 ,27, 36 ,38},
                   {14, 23, 35, 38 ,43},
                   {19, 26 ,42, 49 ,50},
                   {23, 33, 48, 52 ,53},
                   {30 ,40 ,52 ,56 ,64,}};
    int a=13;
   Find_kth_small(arr,a);

    return 0;
}