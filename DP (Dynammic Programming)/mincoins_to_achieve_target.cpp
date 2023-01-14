#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&vec , int n ,int amount , vector<vector<int>>&dp){
   if(n==0){
      if(amount% vec[0]==0){
         return amount/vec[0]; // we are returning the count of coins when our index will be at location 0 , and when the amount is not zero;
      }
      return INT_MAX;
   }
   if(amount == 0) return 0;
   if(dp[n][amount] != -1) return dp[n][amount];
   int noTake = 0 + solve(vec,n-1,amount,dp);
   int take = INT_MAX;
   if(vec[n]<= amount)  take = 1 + solve(vec,n,amount-vec[n],dp);
   return dp[n][amount] = min(take,noTake);
}

int main(){
   
   vector<int>coins{1,2,3,5};
   int amount  = 7;
   vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , -1));
   cout<<solve(coins, coins.size()-1, amount , dp)<<endl;
}