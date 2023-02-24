// this is a dp solution and time complexity of the solution is O(n* m) ans space complexity is O(n*m)+O(n+m);

#include<bits/stdc++.h>
using namespace std;

int distinctSubsiquence(string &s1 , string &s2 , int n, int m , vector<vector<int>>&dp){
   if(m<0) return 1;
   if(n<0) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   if(s1[n]==s2[m]) return dp[n][m] = distinctSubsiquence(s1,s2,n-1,m-1,dp) + distinctSubsiquence(s1,s2,n-1,m,dp);
   else return dp[n][m] = distinctSubsiquence(s1,s2,n-1,m,dp);
}

int main(){
   string s1 = "babgbag";
   string s2 = "bag";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n,vector<int>(m , -1));
   cout<<distinctSubsiquence(s1,s2,n-1,m-1,dp)<<endl;
}