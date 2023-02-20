// this isbottom up approach and the time complexity of the solution is O(n*m) and space complexity is O(n*m)

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "abdk", s2 = "bdcs";
   int n = s1.size() , m = s2.size() , ans=INT_MIN;
   vector<vector<int>>dp(n+1 , vector<int>(m+1,0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
            ans = max(ans,dp[i][j]);
         }
         else dp[i][j] = 0;
      }
   }
   cout<<ans<<endl;
}