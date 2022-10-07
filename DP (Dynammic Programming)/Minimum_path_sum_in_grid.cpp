// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.

//-------------------------------------------------------------------------------

//this is a top down approach and the time complexity for the solution is exponential and space complexity is O(n*m)+auxilliary stack space
#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>&vec,int i, int j, vector<vector<int>>&dp){
   if(i==0 && j==0) return vec[i][j];
   if(i<0 || j<0) return 1e9;
   if(dp[i][j]!=-1) return dp[i][j];
   int up =  vec[i][j]+minPathSum(vec,i-1,j,dp);
   int left = vec[i][j]+minPathSum(vec,i,j-1,dp);

   return dp[i][j]=min( left,up);
}

int main(){
   vector<vector<int>>vec{
      {10,3,2},
      {1,20,1},
      {20,3,2},
   },dp(vec.size(),vector<int>(vec[0].size(),-1));
   cout<<minPathSum(vec,vec.size()-1,vec[0].size()-1,dp)<<endl;
}