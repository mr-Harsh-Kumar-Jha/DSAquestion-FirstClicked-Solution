// you are give a triangular array list 'Triangle' . Your task is to retun a minimum path sum to reach from the top to the bottom row .

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