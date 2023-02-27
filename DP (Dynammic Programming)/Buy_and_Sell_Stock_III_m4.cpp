// the simple logic behind bringing the time complexity to O(n*4) from (O(n*2*3)=O(n*6)) is that we only need 4 transaction to perform 2 buy ans sell operation .

#include<bits/stdc++.h>
using namespace std;

int buySellStock(int ind , int transaction, vector<int>&price , int n, vector<vector<int>>&dp){
      if(ind==n || transaction == 4) return 0;
      if(dp[ind][transaction]!=-1) return dp[ind][transaction];
      int profit = 0;
      if(transaction%2==0){
         profit = max((-price[ind]+buySellStock(ind+1 , transaction+1, price ,n,dp)),(0+buySellStock(ind+1, transaction,price,n,dp)));
      }
      else{
         profit = max((price[ind]+buySellStock(ind+1 , transaction+1, price ,n,dp)),(0+buySellStock(ind+1, transaction,price,n,dp)));
      }
      return dp[ind][transaction] = profit;
}

int main(){
   vector<int>price{3,3,5,0,0,3,1,4};
   int n = price.size();
   vector<vector<int>>dp(n,vector<int>(5,-1));
   cout<<buySellStock(0 , 0, price, n,dp)<<endl;
}