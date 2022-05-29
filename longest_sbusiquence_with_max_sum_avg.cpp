#include<bits/stdc++.h>
#define N 4
using namespace std;

void maxAvgSubsequences(int arr[] , int sum2)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, N);
    int sum=0;
    int count=0;
    int sum3=sum2;
    float avg1,avg2;
   float max=INT_MIN;
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
       sum3=sum2;
       sum=0;
       count=0;
        for (int j = 0; j < N-1; j++)
        {
            /* Check if jth bit in the counter is set
                If set then take  jth element from arr[]  as subsiquence element*/
            if (counter & (1<<j)){
               count=count+1;
               sum=sum+arr[j];

            }
        }
      sum3=sum3-sum;
       avg1=sum/count;
       avg2=sum3/(N-count);
       if(avg1+avg2>max){
         max=avg1+avg2;
       }
    }
    cout<<max<<endl;
}

int main(){
   int arr[]={50,40,30,20};
   int sum=0;
   int sum2=0;
   // sort(arr,arr+N);
   for(int i=0;i<N;i++){
      sum2=sum2+arr[i];
   }
   maxAvgSubsequences(arr , sum2);

   // float avg1,avg2;
   // float max=INT_MIN;

   // for(int i=0;i<N-1;i++){
   //    sum=sum+arr[i];
   //    sum2=sum2-arr[i];
   //    avg1=sum/(i+1);
   //    avg2=sum2/(N-i-1);
   //    if(avg1+avg2>max){
   //       max=avg1+avg2;
   //    }
   // }
   // cout<<max<<endl;
}