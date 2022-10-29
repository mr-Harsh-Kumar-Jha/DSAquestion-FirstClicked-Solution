//You are given an array/list Arr of N positive integers and an integer k . Your task is to check if their exist a subsequences in Arr with a sum equal to k .

// Note return true if their exist a subset with sum equal to k otherwise return false

//-----------------------------------------------------------------------------

//Time complexity of the solution is O(n*target) and space complexity of the solution is O(n*target)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,4,2,20,10,21};
   int n = vec.size();
   int target = 45;
   vector<vector<bool>>dp(n,vector<bool>(target+1,0));
   for(int i=0;i<n;i++){
      dp[i][0]=true;
   }
   dp[0][vec[0]]=true;
   for(int i=1;i<=n-1;i++){
      for(int tar=1;tar<=target;tar++){
         int take = false;
         if(tar >= vec[i]) take = dp[i-1][tar-vec[i]];
         int notTake = dp[i-1][tar];
         dp[i][tar]= take | notTake;
      }
   }
   cout<<dp[n-1][target]<<endl;
}