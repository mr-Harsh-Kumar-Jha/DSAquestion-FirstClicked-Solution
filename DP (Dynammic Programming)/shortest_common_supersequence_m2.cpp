// the simple approach we can get the longest common subsequence and count it once and reset other letters are counted as usuals .

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "gloort";
   string s2 = "brout";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
         else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
      }
   }
   cout<<n+m-dp[n][m]<<endl;
}