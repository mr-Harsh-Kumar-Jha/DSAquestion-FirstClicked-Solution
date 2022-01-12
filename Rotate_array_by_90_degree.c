// time complexity is O(n^2) and space complexity is O(n^2)


#include <stdio.h>
#define R 4
#define C 4

void Rotate_90(int arr[][C], int a[][C]){
    int k=0,L=0;
    for(int i=0;i<C;i++){
        for(int j=R-1;j>=0;j--) {
                a[k][L]=arr[j][i];
                if(L==C-1){
                    L=0;
                    k=k+1;
                }
                else
                  L+=1;
        }
    }
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main() {

   int arr[][C]={{16, 28, 60, 64},
                  {22, 41, 63, 91},
                  {27, 50, 87, 93},
                  {36, 78, 87, 94 }};
   int a[R][C];

    Rotate_90(arr,a);

    return 0;
}