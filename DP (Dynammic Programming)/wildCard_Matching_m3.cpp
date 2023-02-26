// time complexity is O(n*m) and space complexity is O(n*m)

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1  = "aab";
   string s2 = "c*a*b";
   int n = s1.length();
   int m = s2.length();
   vector<vector<bool>>dp(n+1 , vector<bool>(m+1,0));
   dp[0][0] = true;
   for(int i = 1;i<=m;i++){
      if(s2[i-1]!='*') {
         dp[0][i]= false;
         break; // here break is used because even if we get an alphabate instead of '*' we dont have to consider the further case as true
      }
      else dp[0][i] = false;
   }
   for(int i=1;i<=n;i++){
      dp[i][0] = false;
   }
   for(int i=1;i<=n;i++){
      for(int j = 1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s2[j-1]=='?') dp[i][j] = dp[i-1][j-1];
         else if(s2[j-1]=='*'){
            dp[i][j] = (dp[i][j-1] | dp[i-1][j]);
         }
         else dp[i][j] = false;
      }
   }
   cout<<dp[n][m]<<endl;
}