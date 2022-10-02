// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

//-----------------------------------------------------------------------------------

// this is a bottom up approach and the time complexity is O(n*4*3) and space complexity is O(n*4)

#include <bits/stdc++.h>
using namespace std;

int maxSolve(vector<vector<int>> &vec, vector<vector<int>> &dp)
{
   dp[0][0] = max(vec[0][1], vec[0][2]);
   dp[0][1] = max(vec[0][0], vec[0][2]);
   dp[0][2] = max(vec[0][0], vec[0][1]);
   dp[0][3] = max(vec[0][0], max(vec[0][1], vec[0][2]));

   for (int ind = 1; ind < vec.size() ; ind++)
   {
      for (int last = 0; last < 4; last++)
      {
         dp[ind][last]=0;
         int maxi = INT_MIN;
         for (int task = 0; task < 3; task++)
         {
            if (task != last)
            {
               int ans = vec[ind][task] + dp[ind - 1][task];
               dp[ind][last] = max(dp[ind][last], ans);
            }
         }
      }
   }
   return dp[vec.size()-1][3];
}

int main()
{
   vector<vector<int>> vec{
       {1, 100, 3},
       {9, 10, 8},
       {12, 11, 13},
   },
       dp(vec.size(), vector<int>(4, 0));
   cout << maxSolve(vec, dp) << endl;
}