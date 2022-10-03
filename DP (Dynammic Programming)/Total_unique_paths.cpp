#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int n,int m,vector<vector<int>>&dp){
   if(n==0 && m==0) return 1;
   if(n<0 || m<0) return 0;
   if(dp[m][n]!=-1) return dp[m][n];
   int left = totalUniquePath(n-1,m,dp);
   int up = totalUniquePath(n,m-1,dp);
   return dp[m][n]=left+up;
}

int main(){
   int n,m;
   cin>>n>>m;
   vector<vector<int>>dp(m,vector<int>(n,-1));
   cout<<totalUniquePath(n,m,dp)<<endl;
}