// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// ===========================================================================

// this question is very similar to partition with given difference as we have been give an array where we have to select numbers when carried on an addition or substraction gives us target.

#include<bits/stdc++.h>
using namespace std;

int findTargetSum(vector<int>&vec , int ind , int target , vector<vector<int>>&dp){
   if(target==0) return 1;
   if(ind==0) return vec[ind]==target;
   if(dp[ind][target]!=-1) return dp[ind][target];
   int take = 0;
   if(vec[ind]<=target){
      take = findTargetSum(vec,ind-1,target-vec[ind] ,dp);
   }
   int noTake = 0 + findTargetSum(vec,ind-1,target,dp);
   return (take+noTake);
}

int main(){
   vector<int>vec{2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
   int n = vec.size();
   int target = 1000;
   int total = 0;

   for(int i=0;i<n;i++){
      total+=vec[i];
   }

   if((total-target)%2==0 && (total-target)>=0){
      int targetToSearched = (total-target)/2;
      vector<vector<int>>dp(n,vector<int>(targetToSearched+1,-1));
      cout<<findTargetSum(vec,n-1,targetToSearched,dp)<<endl;
      return 0;
   }
   cout<<0<<endl;
   return 0;
}