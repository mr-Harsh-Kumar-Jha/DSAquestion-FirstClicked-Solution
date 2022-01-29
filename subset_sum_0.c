#include<stdio.h>

int main(){
   //   #ifndef ONLINE_JUDGE
   //   freopen("input.txt", "r" ,stdin);
   //   freopen("output.txt", "w" ,stdout);
   //   #endif

     int N=5;
     int sum=0;
     int arr[5];
     for(int i=0;i<N;i++){
         scanf("%d",&arr[i]);
     }

     for(int i=0;i<N;i++){
        sum=0;
        for(int j=i;j<N;j++){
             sum=sum+arr[j];
             if(sum==0){
                 printf("ur sub array lies between %d to %d\n",i+1,j+1);
             }
        }
     }
}