//Yoou are given an 'array' of 'N' ppositive integers . Your task ios to find if we can partitation the array in two subsets such that the sum of elements in both subsets is equal .

//-----------------------------------------------------------------------------

// The main key rule that i have used is that this problem is very similar to the subset target problem . Here the only catch is that the target value will be half of the sum of the elements total sum .
// the time complexity of the solution is O(n*target) and space complexity of the solution is O(n*target)+O(n)

#include<bits/stdc++.h>
using namespace std;

bool targetSum(vector<int>&vec,int i , int target,vector<vector<int>>&dp){
   if(target == 0) return true;
   if(i==0) return (vec[i]==target);
   if(dp[i][target] != -1) return dp[i][target];
   int take = false;
   if(vec[i]<= target) take = targetSum(vec,i-1,target-vec[i],dp);
   int noTake = targetSum(vec,i-1,target,dp);
   return dp[i][target] = take | noTake ;
}

int main(){
   vector<int>vec{2,3,3,3,6,7};
   int n = vec.size();
   int totSum = 0;
   for(int i=0; i<n;i++) totSum+=vec[i];

   if(totSum%2!=0) cout<<0<<endl;
   else {
      int target = totSum/2;
      vector<vector<int>>dp(n,vector<int>(target+1,-1));
      cout<<targetSum(vec,n-1,target,dp)<<endl;
   }

}