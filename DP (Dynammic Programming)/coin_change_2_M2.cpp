#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,2,3};
   int n = vec.size();
   int coinSum = 5;
   vector<vector<int>>dp(n,vector<int>(coinSum+1,0));

   for(int i=0;i<=coinSum;i++){
      dp[0][i] = (i%vec[0]==0);
   }

   for(int i=1;i<n;i++){
      for(int j=0;j<=coinSum;j++){
         int take = 0;
         if(vec[i]<=j) take = dp[i][j-vec[i]];
         int notake = dp[i-1][j];
         dp[i][j] = take + notake;
      }
   }
   cout<<dp[n-1][coinSum]<<endl;
}