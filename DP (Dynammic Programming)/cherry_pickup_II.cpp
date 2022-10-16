// Ninja has a grid of size 'R' X 'C' . Each cell of the grid contains some chocolates . Ninja has two frnds Alice and Bob , and he wants to collect as many chocolates as possible with the help of the friends . Initially Allice , is in the top Left i.e (o,o) and his frnd is at (o,c-1) on the grid . Each one can move from their current cell to the cell just below them . When anyone passes from any cell, he will pick all chocolates in it , and the no of chocolates in that cell will become zero . If both stay in the same cell , only one of them will pick the chocolates in it .

// if Alice or bob is at (i,j) then they can move to (i+1,j) , (i+1,j-1) , (i+1 , j+1) They will always stay in grid . Ypur task is to find the maximum no of chocolates that ninja can colllect with the help of his friend by following the above rules .

//-------------------------------------------------------------------------------

// this is a top down using recursive approach and time complexity is  O((n*m*m)*9) and space complexity is O(n*m*m) .

#include<bits/stdc++.h>
using namespace std;

int cherryPick(vector<vector<int>>&vec,int i2,int j1,int j2 ,vector<vector<vector<int>>>&dp){
      if(j1<0 || j1>vec[0].size()-1 || j2>vec[0].size()-1 || j2<0) return -1e8;
      if(i2==vec[0].size()-1){
            if(j1==j2) return vec[i2][j1];
            else return vec[i2][j1]+vec[i2][j2];
      }
      if(dp[i2][j1][j2]!=-1) return  dp[i2][j1][j2];
      int maxi = -1e8;
      for(int i=-1;i<=1;i++){
         for(int j=-1;j<=1;j++){
            int value=0;
            if(j1==j2) return maxi=max(maxi,vec[i2][j1]);
            else value=vec[i2][j1]+vec[i2][j2];
            value+=cherryPick(vec,i2+1,j1+i,j2+j,dp);
            maxi=max(maxi,value);

         }
    }
    return dp[i2][j1][j2]=maxi;
}

int main(){
   vector<vector<int>>vec{
      {1,2,3,4},
      {10,32,21,22},
      {11,1,44,2},
      {100,200,300,100},
   };
   vector<vector<vector<int>>>dp(vec.size(),vector<vector<int>>(vec[0].size(),vector<int>(vec[0].size(),-1)));
   cout<<cherryPick(vec,0,0,vec[0].size()-1,dp)<<endl;
}