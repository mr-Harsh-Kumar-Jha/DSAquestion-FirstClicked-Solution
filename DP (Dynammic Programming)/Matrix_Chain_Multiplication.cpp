#include<bits/stdc++.h>
using namespace std;

int matrixChainManip(int i, int j, vector<int>&vec, vector<vector<int>>&dp){
   if(i==j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   int mins = 1e9;
   for(int k = i;k<j;k++){
     int score = (vec[i-1]*vec[k]*vec[j])+matrixChainManip(i,k,vec , dp)+matrixChainManip(k+1,j,vec, dp);
      mins = min(mins,score);
   }
   return dp[i][j]=mins;
}

int main(){
   vector<int>vec{4 ,5 ,3 ,2};
   int n = vec.size();
   vector<vector<int>>dp(n,vector<int>(n,-1));
   cout<<matrixChainManip(1, n-1, vec,dp)<<endl;
}