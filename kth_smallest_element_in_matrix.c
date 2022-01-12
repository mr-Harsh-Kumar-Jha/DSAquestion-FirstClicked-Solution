// Online C compiler to run C program online
#include <stdio.h>
#include<limits.h>
#define R 4
#define C 4

void Sort(int arr[][C],int a[][C]){
    int temp,temp2;
    int M=0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            temp=arr[i][j];
            arr[i][j]=INT_MAX;
            for(int k=i;k<R;k++)
            {
                for(int L=0;L<C;L++)
                {
                     if(temp>arr[k][L]){
                        temp2=temp;
                        temp=arr[k][L];
                        arr[k][L]=temp2;
                    }
                }
            }
            if(M<C)
            {
              a[i][M]=temp;
              M++;
            }
            else{
                M=0;
                a[i][M]=temp;
                M++;
            }
        }
    }
}

void Find_kth_small(int arr[][C],int term_no,int a[][C]){
    int i, j;
    i=(term_no-1)/R;
    j=(term_no-1)%R;

    Sort(arr,a);

    printf("%d",a[i][j]);

}

int main() {

   int arr[][C]={{16, 28, 60, 64},
                  {22, 41, 63, 91},
                  {27, 50, 87, 93},
                  {36, 78, 87, 94 }};
    int a=14;
    int arr2[R][C];
   Find_kth_small(arr,a,arr2);

    return 0;
}