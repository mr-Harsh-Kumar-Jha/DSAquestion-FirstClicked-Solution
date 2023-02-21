// the logic is very simple as u have to insert only (n-maxPalindromicSequence) because if a palindomic subsequence is present then hame baki ko palindrome banana padega .

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s = "mbadm";
   int n = s.length();
   string s2 = s;
   reverse(s2.begin() , s2.end());
   int m = s2.length();
   vector<vector<int>>dp(n+1, vector<int>(m+1,0));

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s[i-1]==s2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
         else dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
      }
   }
   cout<<n-dp[n][m]<<endl;
}