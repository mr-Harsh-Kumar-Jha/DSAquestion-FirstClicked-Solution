// this is a tabulation approach and the time complexity 0f the solutiion is O(n*length) and space complexity of the solution is O(n*length) 

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>price{2,5,7,8,10};
   int n = price.size();
   int length = 10;
   vector<vector<int>>dp(n, vector<int>(length+1,0));
   for(int i=0;i<=length;i++){
      dp[0][i] = i*price[0];
   }
   for(int i=1;i<n;i++){
      for(int j=0;j<=length;j++){
         int take = INT_MIN;
         if(j>=(i+1)) take = price[i]+dp[i][j-(i+1)];
         int noTake = 0 + dp[i-1][j];
         dp[i][j]=max(take,noTake);
      }
   }
   cout<<dp[n-1][length]<<endl;
}