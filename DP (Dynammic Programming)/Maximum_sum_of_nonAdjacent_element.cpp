// this is a top down approach and time complexity of this algo is exponential and space complexity O(n)+auxillary space of O(n).

#include<bits/stdc++.h>
using namespace std;

int maxSum(int ind , vector<int>&vec, vector<int>&dp){
   if(ind == -1) return 0;
   if(ind == 0) return vec[ind];
   if(dp[ind]!=-1) return dp[ind];
   int take = vec[ind]+maxSum(ind-2, vec,dp);  //here value is been taken
   int nTake = 0+maxSum(ind-1,vec,dp); // above perticular value is not been taken
   return dp[ind]=max(take,nTake);
}

int main(){
   vector<int>vec{2,3,4,9,3};
   vector<int>dp(vec.size(),-1);
   cout<<maxSum(vec.size()-1,vec,dp)<<endl;
}