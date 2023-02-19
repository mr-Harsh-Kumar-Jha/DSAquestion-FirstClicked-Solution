// THIS IS A RECURSIVE SOLUTION AND THE TIME COMPLEXITY OF THE SOLUTION IS EXPONWNTIAL AND THE SPACE COMPLEXITY IS O(N*LENGTH) + AUXILLIARY SPACE .

#include<bits/stdc++.h>
using namespace std;

int rodCutAmt(vector<int>&price , int n , int length ,vector<vector<int>>&dp){
   if(length == 0) return 0;
   if(n==0){
      return (length)*price[0];
   }
   if(dp[n][length]!=-1) return dp[n][length];
   int take = INT_MIN;
   if(length>=(n+1)) take = price[n]+rodCutAmt(price, n, length-(n+1),dp);
   int noTake = 0 + rodCutAmt(price,n-1, length,dp);
   return dp[n][length]=max(take,noTake);
}

int main(){
   vector<int>price{2,5,7,8,10};
   int n = price.size();
   int length = 10;
   vector<vector<int>>dp(n, vector<int>(length+1,-1));
   cout<<rodCutAmt(price,n-1,length,dp)<<endl;
}