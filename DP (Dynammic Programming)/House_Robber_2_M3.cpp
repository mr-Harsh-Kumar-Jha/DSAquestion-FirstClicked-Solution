
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//-----------------------------------------------------------------------------------

//This is a Bottom up approach where time complexity of the solution is O(n) and space complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{2, 4, 5, 1, 6} , dp(vec.size(),-1);
   int ans1,ans2;

   //this is a case where we are checking in the range 0 - (n-2)

   dp[0]=vec[0];
   for(int i=1;i<vec.size()-1;i++){
      int pick = vec[i];
      if(i>1) pick+=dp[i-2];
      int noPick = 0+dp[i-1];
      dp[i]=max(pick,noPick);
   }
   ans1=dp[vec.size()-2];

//this is a second part where where we are checking max in the range of 1 - n-1;

   fill(dp.begin(),dp.end(),-1);
   dp[1]=vec[1];
    for(int i=2;i<vec.size();i++){
      int pick = vec[i];
      if(i>2) pick+=dp[i-2];
      int noPick = 0+dp[i-1];
      dp[i]=max(pick,noPick);
   }
   ans2=dp[vec.size()-1];

   cout<<max(ans1,ans2)<<endl;
}