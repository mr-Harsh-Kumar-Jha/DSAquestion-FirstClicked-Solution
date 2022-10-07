// this is a resurcive solution

#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>&vec,int i, int j){
   if(i==0 && j==0) return vec[i][j];
   if(i<0 || j<0) return 1e9;
   int up =  vec[i][j]+minPathSum(vec,i-1,j);
   int left = vec[i][j]+minPathSum(vec,i,j-1);

   return min( left,up);
}

int main(){
   vector<vector<int>>vec{
      {10,3,2},
      {1,20,1},
      {20,3,2},
   };
   cout<<minPathSum(vec,vec.size()-1,vec[0].size()-1)<<endl;
}