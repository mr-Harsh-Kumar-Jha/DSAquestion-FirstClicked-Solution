//time complexity of the solution is O(n*m) and space complexity is O(n*m);

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "defg";
   string s2 = "edgf";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   // for(int i=0;i<n;i++) dp[i][0] = 0;         no need of these condition
   // for(int i=0;i<m;i++) dp[0][i] = 0;

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
         else dp[i][j] = max(dp[i-1][ j] , dp[i ][j-1]);
      }
   }
   cout<<dp[n][m]<<endl;
}