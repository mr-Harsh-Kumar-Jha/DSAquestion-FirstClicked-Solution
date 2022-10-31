// You are given an array containing N non-negative integers . Your Task is to Partition this array into two subsets such that the absolute difference between subset sums is minimum .

// Your task is to find the minimum absolute difference considering any valid division of the array element .

//---------------------------------------------------------------------------

// time complexity of the solution is O(2^n) i.e. Exponential in nature vand space complexity is O(n) which is a stack space .

#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> vec{1, 2, 3, 4};
   int n = vec.size();
   int target = 0;
   for (int i = 0; i < n; i++)
      target += vec[i];
   vector<vector<int>> dp(n, vector<int>(target + 1, -1));
   for (int i = 0; i < n; i++)
      dp[i][0] = true;
   dp[0][vec[0]] = true;
   for (int i = 1; i < n; i++)
   {
      for (int tar = 1; tar <= target; tar++)
      {
         int take = false;
         if (vec[i] <= tar)
            take = dp[i - 1][tar - vec[i]];
         int noTake = dp[i - 1][tar];
         dp[i][tar] = take | noTake;
      }
   }
   int minDiff = 1e8;
   for (int i = 0; i <= target; i++)
   {
      cout << dp[n - 1][i] << " ";
      if (dp[n - 1][i] == true)
      {
         minDiff=min(minDiff,(target - i)-i);
      }
   }
   cout << minDiff << endl;
}