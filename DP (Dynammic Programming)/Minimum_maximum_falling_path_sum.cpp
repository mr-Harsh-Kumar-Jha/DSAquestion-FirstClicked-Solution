// u are given a n*m matrix filled with integer no's. find the maximum sum that can be obtained from the path starting from any cell in the first row of any cell in the last row .

// from the cell in a row , you can move to another cell directly below the row , or diagonally below left or right . So from a perticular cell , we can move in three directions , Down, Down left diagonal, Down right diagonal .

//----------------------------------------------------------------------------------

// This is a top down approach and time complexity is O(n*m) and space complexity is O(n*m)+O(n)

#include<bits/stdc++.h>
using namespace std;

int minMaxsum(vector<vector<int>>&vec , int i,int j,vector<vector<int>>&dp){
   if(j<0 || j>vec[vec.size()-1].size()-1) return -1e9;
   if(i==0) return vec[0][j];
   if(dp[i][j]!=-1) return dp[i][j];
   int up = vec[i][j] + minMaxsum(vec,i-1,j,dp)  ;
   int upldig = vec[i][j] + minMaxsum(vec,i-1,j-1,dp) ;
   int uprdig =  vec[i][j] + minMaxsum(vec,i-1,j+1,dp);
   return dp[i][j] = max(up,max(upldig,uprdig));
}

int main(){
   vector<vector<int>>vec{
      {1, 2, 10, 4},
      {100, 3, 2, 1},
      {1, 1, 20, 2},
      {1, 2, 2, 1},
   },dp(vec.size(),vector<int>(vec[0].size(),-1));
   int maxi=-1e9;
   for(int i=vec[0].size()-1;i>=0;i--){
      maxi=max(maxi, minMaxsum(vec,vec.size()-1,i,dp));
   }
   cout<<maxi<<endl;
}