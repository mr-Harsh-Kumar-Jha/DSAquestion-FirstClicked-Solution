
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//-----------------------------------------------------------------------------------

//This is a top down approach where time complexity of the solution is exponential and space complexity is O(n)+auxilliary space

#include<bits/stdc++.h>
using namespace std;

int adjrob(vector<int>&vec , int start , int end,vector<int>&dp){
       if(end==start) return vec[start];
       if(end==(start-1)) return 0;
       if(dp[end]!=-1) return dp[end];
       int ans1 = vec[end]+adjrob(vec,start,end-2,dp);
       int ans2 = 0+adjrob(vec,start,end-1,dp);
       return dp[end] = max(ans1,ans2);
}

int main(){
   vector<int>vec{2, 4, 5, 1, 6};
   vector<int>dp(vec.size(),-1);
   int ans1 = adjrob(vec,1,vec.size()-1,dp);
   fill(dp.begin(), dp.end(), -1);
   int ans2 = adjrob(vec,0,vec.size()-2,dp);

   cout<<max(ans1,ans2)<<endl;
}