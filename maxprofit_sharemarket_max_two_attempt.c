#include<stdio.h>

int main(){
    int a[] = {2, 30, 8, 70, 15,65,80};
    int length = sizeof(a) / sizeof(int);
    printf("your max profit is: Rs.%d", stocks(a, length));


}


int stocks(int a[], int n){
    int i = 0;
    int j = 0;
    int min1 = 214748365 ;
    int max = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    int L=0;
    int index=n;
while(i<n){
        j = n - 1;
        max2=0;
        max=0;
    if(a[i] < a[i + 1] && a[i]!=max2){
        if(a[i]<min1){
           min1 = a[i];

        }
        if(max1 < a[i + 1] - min1){
            max1 = a[i + 1] - min1;
        }
    }
    else {

        if(max1 < a[j] - min1){
            max1 = a[i] - min1;

        }

    }
    while(i < j-1 ){
        if(a[j] > a[j - 1] && a[j] > max2){
            max2 = a[j];
         if(max < max2 - a[j - 1]) {
             max = max2 - a[j - 1];
             index=j-1;
            }
            j = j - 2;
        }
        else{
            if(max < max2 - a[j]){
                max = max2 - a[j];
                index=j;
            }
            j = j - 1;
        }
        if(max3 < max1 + max){

            max3 = max1 + max;

        }
    }

        i = i + 1;
   }
return max3;
}
