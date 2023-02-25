// this is a dp solution where time complexity of the solution is O(n*2) ans spce complexity is O(n*2);

#include<bits/stdc++.h>
using namespace std;

long long buySellstock(int i , int buy , vector<int>&price , int n, vector<vector<int>>&dp){
   if(i==n) return 0;
   int profit = 0;
   if(dp[i][buy]!=-1) return dp[i][buy];
   if(buy){
       profit = max(-price[i]+buySellstock(i+1,0,price, n, dp), 0+buySellstock(i+1,1,price,n, dp));
   }
   else{
      profit =max(price[i] + buySellstock(i+1,1,price, n, dp), 0 + buySellstock(i+1 , 0 , price , n, dp)); // the first statement means we want to again purchse some another stock after selling the ith stock to increase profit , and the second statement means we dont want to sell on the perticular ith value but we can see further price to make it maximum .
   }
   return dp[i][buy] = profit;
}

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<int>>dp(n, vector<int>(2,-1));
   cout<<buySellstock(0 , 1 , price, n ,dp)<<endl;
}