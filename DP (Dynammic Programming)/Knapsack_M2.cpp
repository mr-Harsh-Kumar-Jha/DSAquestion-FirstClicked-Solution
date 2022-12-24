// time complexity of the solution is O(n^2) and space complexity is O(n*weight) . In my sloution repetation of an item is allowed .

#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int> val{160, 350, 120};
   vector<int> wt{1, 2, 1};
   int w = 5;
   int n = val.size();
   vector<vector<int>> dp(n, vector<int>(w + 1, 0));
   for (int i = 1; i <= w; i++) dp[0][i] = dp[0][i-1] + val[0];
   for (int i = 1; i < n; i++) {
      for (int j = 1; j <=w; j++){
         int noTake = 0+dp[i-1][j];
         int take = INT_MIN;
         if(j>=wt[i]) take = val[i]+dp[i][j-wt[i]];
         dp[i][j] = max(take,noTake);
      }
   }
   cout<<dp[n-1][w]<<endl;
}