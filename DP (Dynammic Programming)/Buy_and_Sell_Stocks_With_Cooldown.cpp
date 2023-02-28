// if u sell then u cannot buy in the next day

#include<bits/stdc++.h>
using namespace std;

int buySellStock(int ind , int buy, vector<int>&price , int n,  vector<vector<int>>&dp){
      if(ind>=n) return 0;
      if(dp[ind][buy]!=-1) return dp[ind][buy];
      int profit = 0;
      if(buy){
         profit = max((-price[ind]+buySellStock(ind+1 , buy-1, price,n,dp)), (0+buySellStock(ind+1,buy,price,n,dp)));
      }
      else{
         profit = max((price[ind]+buySellStock(ind+2,buy+1,price, n,dp)), (0+buySellStock(ind+1,buy,price,n,dp)));
      }
      return dp[ind][buy] = profit;
}

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<int>>dp(n, vector<int>(2,-1));
   cout<<buySellStock(0 , 1 , price, n,dp)<<endl;
}