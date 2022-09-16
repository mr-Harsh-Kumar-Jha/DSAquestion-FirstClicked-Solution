// this is a top down approach of DP and here time complexity is exponential

#include<bits/stdc++.h>
using namespace std;

int minPow(int stairs , vector<int>& pow , vector<int>& dp){
   if(stairs == 0) return 0;
   if(dp[stairs]!=0) return dp[stairs];
   int left = minPow(stairs-1 , pow, dp)+ abs(pow[stairs]-pow[stairs-1]);
    int right = INT_MAX;
   if(stairs>1)
     right = minPow(stairs-2, pow, dp)+abs(pow[stairs]-pow[stairs-2]);
   return dp[stairs]= min(left ,  right);
}

int main(){
   vector<int>pow{10,30,20,60,40};
   vector<int> dp(pow.size(),0);
   minPow(pow.size()-1,pow,dp);
   cout<<dp[pow.size()-1];
}