// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.

// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.

// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

//-----------------------------------------------------------------------------------

// this is a top Down approach and time complexity is O(n*n) and space complexity O(n*m)+auxilliary stack space

#include<bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>>&A,int i,int j,vector<vector<int>>&dp){
      if(i==A.size()-1) return A[A.size()-1][j];
      if(dp[i][j]!=-1) return dp[i][j];
      int down = A[i][j]+minSumPath(A,i+1,j,dp);
      int diagonal = A[i][j]+minSumPath(A,i+1,j+1,dp);
      return dp[i][j]=min(down , diagonal);
}

int main(){
     vector<vector<int>> A{{2},
                                           {3, 1},
                                           {1, 2, 3}},dp(A.size(),vector<int>(A[A.size()-1].size(),-1));
   cout << minSumPath(A,0,0,dp)<<endl;
}