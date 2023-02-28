#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<int>>dp(n+2, vector<int>(2,0));
   for(int i=n-1;i>=0;i--){
      for(int j = 0 ; j<=1;j++ ){
         if(j){
            dp[i][j] = max((-price[i]+dp[i+1][0]),(0+dp[i+1][1]));
         }
         else dp[i][j] = max((price[i]+dp[i+2][1]),(0+dp[i+1][0]));
      }
   }
   cout<<dp[0][1]<<endl;
}