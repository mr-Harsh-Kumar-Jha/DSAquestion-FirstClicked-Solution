//time complexity of the solution is O(n*m) and space complexity is O(m);

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "defg";
   string s2 = "edgf";
   int n = s1.length();
   int m = s2.length();
   vector<int>prev(m+1, 0) , curr(m+1, 0);
   // for(int i=0;i<n;i++) dp[i][0] = 0;         no need of these condition
   // for(int i=0;i<m;i++) dp[0][i] = 0;

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) curr[j] = 1+prev[j-1];
         else curr[j] = max(prev[ j] , curr[j-1]);
      }
      prev = curr;
   }
   cout<<prev[m]<<endl;
}