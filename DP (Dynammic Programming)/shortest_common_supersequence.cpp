//supersequence means those type of sequence which consists of letters in a perticular order so that it can form s1 and s2 .

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSuper(string &s1 , string &s2 , int n , int m, vector<vector<int>>&dp){
   if(n < 0 || m < 0 ){
      return 0;
   }
   if(dp[n][m]!=-1) return dp[n][m];
   if(s1[n-1]==s2[m-1]) return 1 + shortestCommonSuper(s1,s2,n-1,m-1,dp);
   return 0 + max(shortestCommonSuper(s1,s2,n-1,m,dp),shortestCommonSuper(s1,s2,n,m-1,dp));
}

int main(){
   string s1 = "gloort";
   string s2 = "borut";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
   cout<<(n+m-shortestCommonSuper(s1,s2,n,m ,dp))<<endl;
}