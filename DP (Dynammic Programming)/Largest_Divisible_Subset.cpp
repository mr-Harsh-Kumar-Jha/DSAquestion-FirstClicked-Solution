// the solution is very simple as u can see we are just sorting because we can print ans in any order . and now question is reduces largest divisible subsiquence.

#include<bits/stdc++.h>
using namespace std;

int largestDivisibleSubset(int ind , int prev ,  int n , vector<int>&vec, vector<vector<int>>&dp){
   if(ind==n) return 0;
   if(dp[ind][prev+1]!=-1) return dp[ind][prev];
   int take = INT_MIN;
   if(prev == -1 || vec[ind]%vec[prev]==0) take = 1 + largestDivisibleSubset(ind+1, ind, n, vec, dp);
   int notake = 0 + largestDivisibleSubset(ind+1, prev, n, vec, dp);
   return dp[ind][prev+1] = max(take, notake);
}

int main(){
   vector<int>vec{4,1,16,7,64,33};
   int n = vec.size();
   sort(vec.begin(),vec.end());
   vector<vector<int>>dp(n,vector<int>(n+1,-1));
   cout<<largestDivisibleSubset(0,-1,n,vec,dp)<<endl;
}