// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

//===========================================================================


#include<bits/stdc++.h>
using namespace std;

int findCoin(vector<int>&vec, int coinSum, int n, vector<vector<int>>&dp){
    if(n==0){
      if(vec[0]==0 && coinSum==0) return 2;
      else if( coinSum>=vec[0] && coinSum%vec[0]==0) return 1;
      else if(coinSum==0) return 1;
      else return 0;
    }
    if(dp[n][coinSum]!=-1) return dp[n][coinSum];
    int take = 0;
    if(vec[n]<=coinSum) take = findCoin(vec,coinSum-vec[n],n,dp);
    int notake = findCoin(vec,coinSum,n-1,dp);
    return dp[n][coinSum] = take + notake;
}

int main(){
   vector<int>vec{2};
   int n = vec.size();
   int coinSum = 3;
   vector<vector<int>>dp(n,vector<int>(coinSum+1,-1));
   cout<<findCoin(vec,coinSum,n-1,dp)<<endl;
}