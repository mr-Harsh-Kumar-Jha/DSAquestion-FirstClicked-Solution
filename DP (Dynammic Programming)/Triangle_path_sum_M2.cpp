// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.

// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.

// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

//-----------------------------------------------------------------------------------

// this is a tabulationapproach and time complexity of this solution is O(n*n) and space complexity is O(n*m)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>> A{{2},
                                           {3, 1},
                                           {0, 4, 3}},dp(A.size(),vector<int>(A[A.size()-1].size(),-1));

   for(int i=0;i<A.size();i++){
      dp[A.size()-1][i]=A[A.size()-1][i];
   }
   for(int i=A.size()-2;i>=0;i--){
      for(int j=i;j>=0;j--){
         int down = A[i][j]+dp[i+1][j];
         int dig = A[i][j]+dp[i+1][j+1];
         dp[i][j]=min(down,dig);
      }
   }
   cout<<dp[0][0]<<endl;
}