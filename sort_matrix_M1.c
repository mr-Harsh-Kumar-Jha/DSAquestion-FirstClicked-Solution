//time complexity of this problem is O(n^4).
// Online C compiler to run C program online

/*
   this is solution of totally(i.e row and column wise it is unsorted) unsorted array
*/
#include <stdio.h>
#include <limits.h>
#define R 3
#define C 3

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

 void print(int a[][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[R][C]={{1,5,3},
                   {2,8,7},
                   {4,6,9}};
    int a[R][C];
    Sort(arr,a);
    print(a);
    return 0;
}