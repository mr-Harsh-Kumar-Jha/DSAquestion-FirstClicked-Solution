//time complexity is O(n^3) Not an optimised solution

#include <stdio.h>

void findSame(int arr[][5]){
    int temp;
    int temp2;
    int a=0;
    int count=0;
    for(int i=0;i<1;i++){
        for(int j=0;j<5;j++) {
            temp=arr[i][j];
            if(temp2==temp){
                j=j+1;
                temp=arr[i][j];
            }
            for(int k=1;k<4;k++){
                a=0;
                for(int L=0;L<5;L++){
                    if(temp==arr[k][L]){
                        a=a+1;
                        count=count+1;
                        break;
                    }

                }
                if(a==0){
                   count=0;
                    break;
                }
            }
            if(a!=0){
                temp2=temp;
                printf("%d\n",temp);
            }
        }
    }
}

int main() {

   int arr[][5]={{1, 2, 1, 4, 8},
                {3, 7, 8, 5, 1},
                {8, 7, 7, 3, 1},
                {8, 1, 2, 7, 9}};

    findSame(arr);

    return 0;
}