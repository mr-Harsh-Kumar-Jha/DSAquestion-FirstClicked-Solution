//this is a optimised solution where i have used sliding window algorithm due to which time complexity has reduced to O(N) .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,3,8,4,5,6};
   int n = vec.size();
   int k = 3;
   int start=0 , end=0 ,sum=0 , sumMax = INT_MIN;
   while(end<n){
      if(end-start<=k-1) {
          sum+=vec[end];
          end++;
      }
      else{
         sum-=vec[start];
         sum+=vec[end];
         start++;
         end++;
      }
      sumMax=max(sumMax,sum);
   }
   cout<<sumMax<<endl;
}