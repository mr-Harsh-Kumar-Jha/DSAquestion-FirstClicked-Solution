#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>val{60,50,120};
   vector<int>wt{1,2,5};
   int w = 5;
   int n = val.size();
   vector<vector<int>>dp(n,vector<int>(w+1,0));
   for(int i=0;i<n;i++) dp[i][0]=0;
   for(int i=1;i<n;i++){
      for(int j=1;j<=w;j++){
         int noTake = 0 + dp[i-1][j];
         int take = INT_MIN;
         if(wt[i-1]<=j) take=val[i-1]+dp[i][j-wt[i-1]];
         dp[i][j]=max(dp[i][j],max(noTake,take));
      }
   }
   cout<<dp[n-1][w]<<endl;
}