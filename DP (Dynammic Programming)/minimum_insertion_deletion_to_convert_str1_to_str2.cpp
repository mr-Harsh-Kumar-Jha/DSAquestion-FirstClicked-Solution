// the logic is very simple as we just have to search longest common subsequence and the rest letterns needs to deleted from string 1 and need to be inserted from string 2 .

#include<bits/stdc++.h>
using namespace std;

int minDelinser(string &str1 , string &str2 , int n, int m, vector<vector<int>>&dp){
   if(n<0 || m<0){
       return 0;
   }
   if(dp[n][m]!=-1) return dp[n][m];
   int take = 0;
   if(str1[n-1]==str2[m-1]) return dp[n][m] = 1 + minDelinser(str1,str2,n-1,m-1, dp);
   return dp[n][m] = 0 + max(minDelinser(str1, str2, n-1, m, dp), minDelinser(str1, str2, n, m-1, dp));
}

int main(){
   string s1 = "edl";
   string s2 = "xcqja";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   int ans = minDelinser(s1, s2, n, m , dp);
   cout<<(n+m-(2*ans))<<endl;
}