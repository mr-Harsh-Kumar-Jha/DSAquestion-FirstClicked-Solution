#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int n,int m,vector<vector<int>>&dp){
   if(n==0 && m==0) return 1;
   if(n<0 || m<0) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   int left= totalUniquePath(n,m-1,dp);
   int up = totalUniquePath(n-1,m,dp);
   return dp[n][m]=left+up;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>>dp(n,vector<int>(m,-1));
   cout<<dp.size()<<endl;
   cout<<totalUniquePath(n-1,m-1,dp)<<endl;
}