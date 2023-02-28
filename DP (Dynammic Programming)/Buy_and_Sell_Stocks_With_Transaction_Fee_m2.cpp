#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,3,7,5,10,3};
   int n = price.size();
   int fee = 3;
   vector<vector<int>>dp(n+1,vector<int>(2,0));
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         if(j) dp[i][j] = max((-price[i]+dp[i+1][0]),(0+dp[i+1][1]));
         else dp[i][j] = max((price[i]-fee+dp[i+1][1]),(0+dp[i+1][0]));
      }
   }
   cout<<dp[0][1];
}