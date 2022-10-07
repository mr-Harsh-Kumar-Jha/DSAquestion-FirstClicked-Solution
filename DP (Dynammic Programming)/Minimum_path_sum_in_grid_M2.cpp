// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.

//-------------------------------------------------------------------------------

//this is a bottom up approach and the time complexity for the solution is O(n*m) and space complexity is O(n*m);

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>>vec{
      {10,3,2},
      {1,20,70},
      {20,3,2},
   },dp(vec.size(),vector<int>(vec[0].size(),0));

   for(int i=0;i<vec.size();i++){
      for(int j=0;j<vec[0].size();j++){
         if(i==0 && j==0) dp[i][j]=vec[i][j];
         else{
            int up = vec[i][j];
            int left = vec[i][j];
            if(i>0) up = up +dp[i-1][j];
            else up+=1e9;
            if(j>0) left = left+dp[i][j-1];
            else left+=1e9;
            dp[i][j]=min(up,left);
         }
      }
   }
   cout<<dp[vec.size()-1][vec[0].size()-1]<<endl;
}