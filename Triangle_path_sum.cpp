// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.

// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.

// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

//-----------------------------------------------------------------------------------

// this is a recursive approach and time complexity of this solution is exponential.

#include <bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>>&A,int i,int j){
      if(i==A.size()-1) return A[A.size()-1][j];
      int down = A[i][j]+minSumPath(A,i+1,j);
      int diagonal = A[i][j]+minSumPath(A,i+1,j+1);
      return min(down , diagonal);
}

int main(){
   vector<vector<int>> A{{2},
                                           {3, 1},
                                           {1, 2, 1}};
   cout << minSumPath(A,0,0)<<endl;
}