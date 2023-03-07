#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{4,1,16,7,64,32};
   int n = vec.size();
   sort(vec.begin(),vec.end());
   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
   for(int i=n-1;i>=0;i--){
      for(int j=i-1;j>=-1;j--){
         int take = INT_MIN;
         if(j==-1 || vec[i]%vec[j]==0){
            take = 1 + dp[i+1][i+1];
         }
         int notake = 0 + dp[i+1][j+1];
         dp[i][j+1] = max(take,notake);
      }
   }
   cout<<dp[0][0]<<endl;
}