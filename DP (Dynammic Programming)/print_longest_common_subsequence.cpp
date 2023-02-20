// this is the best possible solution with time complexity of O(n*m ) and space complexity of O(n*m) this is the solution which is done is done using bottom up approach .

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "defg";
   string s2 = "edgf";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n+1,vector<int>(m+1,0));

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
          if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
          else dp[i][j] = 0+max(dp[i-1][j] , dp[i][j-1]);
      }
   }
   int i=n,j=m ,ind = dp[n][m] ;
   char s[dp[n][m]];
   while(i && j){
         if(s1[i-1]==s2[j-1]){
             s[ind-1] = s1[i-1];
             ind--;
             i--;j--;
         }
         else if(dp[i-1][j]>dp[i][j-1]){
            i--;
         }
         else {
            j--;
         }
   }
   for(int i=0;i<dp[n][m];i++){
      cout<<s[i];
   }
   cout<<endl;
}