// here the logic is very similar to buy and sell stock II but he the change is that u just have to add another variable chance which is atmost 2 and u can change it when u sell the stock

#include<bits/stdc++.h>
using namespace std;

 int buySellStock(int ind , int buy, int chance, vector<int>&price , int n,  vector<vector<vector<int>>>&dp){
      if(chance==0) return 0;
      if(ind==n) return 0;
      if(dp[ind][buy][chance]!=-1) return dp[ind][buy][chance];
      int profit = 0;
      if(buy){
         profit = max((-price[ind]+buySellStock(ind+1 , buy-1, chance, price,n,dp)), (0+buySellStock(ind+1,buy, chance,price,n,dp)));
      }
      else{
         profit = max((price[ind]+buySellStock(ind+1,buy+1,chance-1,price, n,dp)), (0+buySellStock(ind+1,buy,chance,price,n,dp)));
      }
      return dp[ind][buy][chance] = profit;
}

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
   cout<<buySellStock(0 , 1 , 2, price, n,dp)<<endl;
}