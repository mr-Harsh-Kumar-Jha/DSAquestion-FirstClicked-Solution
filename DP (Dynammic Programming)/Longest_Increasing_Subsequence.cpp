// this is a simple solution as the concept is that we can

#include<bits/stdc++.h>
using namespace std;

int longestIncreasing(int ind , int prev , vector<int>&vec, int n, vector<vector<int>>&dp){
   if(ind==n) return 0;
   if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
   int take = 0;

   if(prev==-1 || vec[prev]<vec[ind]) take = 1+longestIncreasing(ind+1,ind,vec,n,dp);
   int notake = 0+longestIncreasing(ind+1,prev,vec,n, dp);

   return dp[ind][prev+1]=max(take, notake);
}

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<vector<int>>dp(n, vector<int>(n+1,-1));
   cout<<longestIncreasing(0,-1,vec,n,dp);
}