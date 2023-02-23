// this is a optimised solution of minimum_insertion_deletion_to_convert_str1_to_str2 where time complexity is O(n*m) and 

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "edl";
   string s2 = "xcqja";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
   }
   cout<<(n+m-(2*dp[n][m]))<<endl;
}