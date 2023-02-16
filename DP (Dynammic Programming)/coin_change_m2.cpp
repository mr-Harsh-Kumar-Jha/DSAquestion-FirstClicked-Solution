// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Input: coins = [1,2,5], amount = 11
//  Output: 3
//  Explanation: 11 = 5 + 5 + 1

//==================================================================================

// this is a dp based approch where time complexity of the solution is O(n*amt) ans space complexity is stack_Space+O(n*amt);

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>vec{1,3,2,7};
    int amt = 103;
    vector<vector<int>>dp(vec.size() , vector<int>(amt+1,-1));
   //  cout<<countCoin(vec,amt,vec.size()-1 , dp)<<endl;
   for(int i=0;i<=amt;i++){
      if(i%vec[0]==0) dp[0][i]=i/vec[0];
      else dp[0][i]=INT_MAX;
   }

   for(int i=1;i<vec.size();i++){
      for(int j=0;j<=amt;j++){
         int TakeCount = INT_MAX;
         if (vec[i] <= j){
            TakeCount = 1 + dp[i][j-vec[i]];
         }
         int noTakeCount = dp[i-1][j];
         dp[i][j]=min(noTakeCount, TakeCount); 
      }
   }
   cout<<dp[vec.size()-1][amt]<<endl;
}