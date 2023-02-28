#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{3,2,6,5,0,3};
   int n = price.size();
   int k =2;
   int transaction = 2*k;
   vector<vector<int>>dp(n+1,vector<int>(transaction+1,0));
   for(int i=n-1;i>=0;i--){
         for(int m=transaction-1;m>=0;m--){
            if(m%2==0){
               dp[i][m] = max((-price[i]+dp[i+1][m+1]), dp[i+1][m]);
            }
            else dp[i][m] = max((price[i]+dp[i+1][m+1]), dp[i+1][m]);
         }
   }
   cout<<dp[0][0]<<endl;
}