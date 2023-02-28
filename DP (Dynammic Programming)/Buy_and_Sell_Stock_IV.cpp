// this is similar question to Buy_and_Sell_Stock_III but the difference is that there was atmost 2 transaction but here they have told us to have atmost k chances

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
   int k =3;
   vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
   cout<<buySellStock(0 , 1 , k, price, n,dp)<<endl;
}