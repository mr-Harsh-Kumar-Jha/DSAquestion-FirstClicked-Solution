
#include<bits/stdc++.h>
using namespace std;

int buySell(int ind ,int buy ,vector<int>&price ,int n, int fee, vector<vector<int>>&dp){
   if(ind==n) return 0;
   if(dp[ind][buy]!=-1) return dp[ind][buy];
   int profit = 0;
   if(buy){
      profit = max((-price[ind]+buySell(ind+1,buy-1,price,n,fee,dp)), (0+buySell(ind+1,buy,price,n,fee,dp)));
   }
   else profit = max((price[ind]-fee+buySell(ind+1,buy+1,price,n,fee,dp)), (0+buySell(ind+1,buy,price,n,fee,dp)));

   return dp[ind][buy] = profit;
}

int main(){
   vector<int>price{1,3,2,8,4,9};
   int n = price.size();
   int fee = 2;
   vector<vector<int>>dp(n,vector<int>(2,-1));
   cout<<buySell(0 , 1 ,price , n, fee,dp);
}