// this is a dp based approach and the time complexity of the solution is O(n*m) and space complexity is O(n*m)+auxilliary space

#include<bits/stdc++.h>
using namespace std;

int longestCommonSub(string &s1,string &s2,int n,int m,vector<vector<int>>&dp){
   if(n<0 || m<0) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   if(s1[n]==s2[m]) return dp[n][m] = 1+longestCommonSub(s1,s2,n-1,m-1,dp);
   return dp[n][m]=0+max(longestCommonSub(s1,s2,n-1,m,dp),longestCommonSub(s1,s2,n,m-1,dp));
}

int main(){
   string s1 = "defg";
   string s2 = "edgf";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n,vector<int>(m,-1));
   cout<<longestCommonSub(s1,s2,n-1,m-1,dp)<<endl;
}