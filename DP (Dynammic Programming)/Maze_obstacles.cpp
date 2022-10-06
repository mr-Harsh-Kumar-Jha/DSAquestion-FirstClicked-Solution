//Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

//Now consider if some obstacles are added to the grids. How many unique paths would there be?

//-----------------------------------------------------------------------------------

//this is a top down approch where time complexity if the solution is exponential and space complexity is O(N*M)+ auxilliary stack space;

#include<bits/stdc++.h>
using namespace std;

int mazeObst(vector<vector<int>>&vec , int i, int j, vector<vector<int>> &dp){
   if(i==0 && j==0) return 1;
   if(i<0 || j<0) return 0;
   if(vec[i][j]==1) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   int up = mazeObst(vec,i-1,j,dp);
   int left = mazeObst(vec,i,j-1,dp);
   return dp[i][j] = up+left;
}

int main(){
   vector<vector<int>> A = {{ 0, 0, 0 },
                                                { 0, 1, 0 },
                                                { 0, 0, 0 } }, dp(A.size(), vector<int>(A[0].size() ,-1));
   cout<<mazeObst(A,(A.size()-1),(A[0].size()-1),dp)<<endl;
}