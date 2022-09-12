//this is a memoization technique here dp id used which is a top down approach .
// time complexity is exponential and space complexity is O(n)+auxillary space;

#include<bits/stdc++.h>
using namespace std;

int solveSteps(int stairs , vector<int>&dp){
   if(stairs == 0) return 1;
   if(stairs == 1) return 1;
   if(dp[stairs]!=-1) return dp[stairs];
   return dp[stairs] = solveSteps(stairs-1 , dp) + solveSteps(stairs-2 , dp);

}

int main(){
    int stairs;
    cin>>stairs;
    vector<int>dp(stairs+1 , -1);
    solveSteps(stairs , dp);
   cout<<dp[stairs]<<endl;
}