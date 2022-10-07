// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.

//-------------------------------------------------------------------------------

//this is a space optimization approach and the time complexity for the solution is O(n*m) and space complexity is O(m);

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>>vec{
      {10,3,2},
      {1,20,1},
      {20,3,2},
   };
   vector<int>prev(vec[0].size(),0);

   for(int i=0;i<vec.size();i++){
      vector<int>curr(vec[0].size(),0);
      for(int j=0;j<vec[0].size();j++){
         if(i==0 && j==0) curr[j]=vec[i][j];
         else{
            int up = vec[i][j];
            int left = vec[i][j];
            if(i>0) up = up +prev[j];
            else up+=1e9;
            if(j>0) left = left+curr[j-1];
            else left+=1e9;
            curr[j]=min(up,left);
         }
      }
      prev=curr;
   }
   cout<<prev[vec[0].size()-1]<<endl;
}