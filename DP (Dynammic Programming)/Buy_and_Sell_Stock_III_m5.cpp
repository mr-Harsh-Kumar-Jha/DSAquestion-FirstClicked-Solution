// the simple logic behind bringing the time complexity to O(n*4) from (O(n*2*3)=O(n*6)) is that we only need 4 transaction to perform 2 buy ans sell operation .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{3,3,5,0,0,3,1,4};
   int n = price.size();
   vector<vector<int>>dp(n+1,vector<int>(5,0));
   for(int i=n-1;i>=0;i--){
      for(int j=3;j>=0;j--){
        if(j%2==0){
         dp[i][j]= max((-price[i]+dp[i+1][j+1]),(0+dp[i+1][j]));
        }
        else dp[i][j] = max((price[i]+dp[i+1][j+1]), (0+dp[i+1][j]));
      }
   }
   cout<<dp[0][0]<<endl;
}