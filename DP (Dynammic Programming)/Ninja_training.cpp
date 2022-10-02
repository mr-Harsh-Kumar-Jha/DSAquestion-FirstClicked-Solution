// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

//-----------------------------------------------------------------------------------

//this is a top down approach where time complexity is exponential and space complexity is O(n*4);

#include <bits/stdc++.h>
using namespace std;


int maxSolve(int ind, int prev, vector<vector<int>> &vec , vector<vector<int>>&dp)
{
   if (ind == 0)
   {
      int maxi = INT_MIN;
      for (int i = 0; i < 3; i++)
      {
         if (i != prev && vec[ind][i] > maxi)
         {
            maxi = vec[ind][i];
         }
      }
      return maxi;
   }
   if(dp[ind][prev]!=-1) return dp[ind][prev];

   int maxi = INT_MIN;
   for(int task=0;task<3;task++){
      if(task!=prev){
         int ans = vec[ind][task] + maxSolve(ind-1,task,vec,dp);
         maxi=max(maxi,ans);
      }
   }
   return dp[ind][prev] = maxi;
}

int main()
{
   vector<vector<int>> vec{
       {1, 2, 3},
       {9, 10, 8},
       {12, 11, 13},
   },dp(vec.size(),vector<int>(4,-1));
   cout << maxSolve(vec.size()-1, 3, vec,dp) << endl;
}