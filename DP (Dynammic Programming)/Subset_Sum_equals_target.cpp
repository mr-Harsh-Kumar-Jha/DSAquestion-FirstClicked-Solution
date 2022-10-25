//You are given an array/list Arr of N positive integers and an integer k . Your task is to check if their exist a subset in Arr with a sum equal to k .

// Note return true if their exist a subset with sum equal to k otherwise return false

//-----------------------------------------------------------------------------

// This is  a top down approach and time complexity of the solution is O(2^n) and space complexity is O(n)+auxilliafy space of O(n) .

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>&vec, int n, int target,vector<int>&dp){
   if(target == 0) return true;
   if(n==0) return vec[0]==target;
   if(dp[n]!=-1 )return dp[n];
   int notTake = subsetSum(vec,n-1,target,dp);
   int take = false;
   if(target>=vec[n]) take = subsetSum(vec,n-1,target-vec[n],dp);
   return take||notTake;

}

int main(){
   vector<int>vec{1,4,2,20,10,21};
   int n = vec.size();
   int target = 45;
   vector<int>dp(n,-1);
   cout<<subsetSum(vec,n-1,target,dp)<<endl;
}