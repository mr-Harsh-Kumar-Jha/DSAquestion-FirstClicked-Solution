#  include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{4 ,5 ,3 ,2};
   int n = vec.size();
   vector<vector<int>>dp(n,vector<int>(n,0));
   for(int i=n-1;i>=1;i--){
      for(int j = i+1;j<n;j++) {
          int mins = 1e9;
         for(int k = i;k<j;k++){
            int score = (vec[i-1]*vec[k]*vec[j])+dp[i][k]+dp[k+1][j];
            mins = min(mins,score);
         }
         dp[i][j] = mins;
      }
   }
   cout<< dp[1][n-1]<<endl;
}