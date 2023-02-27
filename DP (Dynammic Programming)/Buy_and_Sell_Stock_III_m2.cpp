#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{1,2,3,4,5};
   int n = price.size();
   vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
   for(int i=n-1;i>=0;i--){
      for(int j=0;j<=1;j++){
         for(int k=1;k<=2;k++){
            int profit = 0;
            if(j){
                dp[i][j][k] = max((-price[i]+dp[i+1][0][k]), (0+dp[i+1][1][k]));
            }
            else{
                dp[i][j][k]= max((price[i]+dp[i+1][1][k-1]), (0+dp[i+1][0][k]));
            }
         }
      }
   }
    cout<<dp[0][1][2]<<endl;
}