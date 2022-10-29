//You are given an array/list Arr of N positive integers and an integer k . Your task is to check if their exist a subsequences in Arr with a sum equal to k .

// Note return true if their exist a subset with sum equal to k otherwise return false

//-----------------------------------------------------------------------------

// This is  a top down approach and time complexity of the solution is O(n*target) and space complexity is O(n*target)+auxilliafy stack space of O(n) .

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>&vec, int n, int target,vector<vector<int>>&dp){
   if(target == 0) return true;
   if(n==0) return vec[0]==target;
   if(dp[n][target]!=-1 ) return dp[n][target];
   int take = false;
   if(target>=vec[n]) take = subsetSum(vec,n-1,target-vec[n],dp);
   int notTake = subsetSum(vec,n-1,target,dp);
   return dp[n][target]= take | notTake;

}

int main(){
   vector<int>vec{2,3,1,1};
   int n = vec.size();
   int target = 4;
   vector<vector<int>>dp(n,vector<int>(target+1,-1));
   cout<<subsetSum(vec,n-1,target,dp)<<endl;
}

