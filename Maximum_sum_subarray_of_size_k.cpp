//this is a brute force approach and the complexity of the solution is O(N*K) it can be further optimised using sliding window Algorithm 

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,3,2,4,5,6};
   int n = vec.size();
   int k = 5;
   int sum =0;
   int maxSum = INT_MIN;
   for(int i=0; i<=n-k; i++){
      for(int j=i;j<i+k;j++){
         sum+=vec[j];
      }
      if(sum > maxSum) maxSum = sum;
      sum=0;
   }
   cout<<maxSum<<endl;
   return 0;
}