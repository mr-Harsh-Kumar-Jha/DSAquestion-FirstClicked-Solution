#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<vector<int>>dp(n+1,vector<int>(n+1,0));
   for(int i=n-1;i>=0;i--){
      for(int j=i-1;j>=-1;j--){
         int take = 0;
         if(j==-1 || vec[j]<vec[i]) take = 1+dp[i+1][i+1]; // second parameter me hamne +1 isliye kiya hain because jaise ki ham ham observe kar rahe the in recursive solution that our ans is store in (prev+1)th position , so we will use the +1th position on very search . .
         int notake = 0+dp[i+1][j+1];
         dp[i][j+1]=max(take, notake);
      }
   }
   cout<<dp[0][0]<<endl;
}