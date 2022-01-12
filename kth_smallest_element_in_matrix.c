// Very great optimised solution O(1)

#include <stdio.h>
#define R 4
#define C 4

void Find_kth_small(int arr[][C],int term_no){
    int i, j;
    i=(term_no-1)%R;
    j=(term_no-1)/R;

    printf("%d",arr[i][j]);

}

int main() {

   int arr[][C]={{16, 28, 60, 64},
                  {22, 41, 63, 91},
                  {27, 50, 87, 93},
                  {36, 78, 87, 94 }};
    int a=6;
   Find_kth_small(arr,a);

    return 0;
}