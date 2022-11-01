// You are given an array containing N non-negative integers . Your Task is to Partition this array into two subsets such that the absolute difference between subset sums is minimum .

// Your task is to find the minimum absolute difference considering any valid division of the array element .

//---------------------------------------------------------------------------

// time complexity of the solution is O(n*target) and space complexity is            O(n*target) .

#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> vec{1, 5, 3, 6};
   int n = vec.size();
   int target = 0;
   for (int i = 0; i < n; i++)
      target += vec[i];
   vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
   for (int i = 0; i < n; i++) dp[i][0] = true;
   dp[0][vec[0]] = true;
   for (int i = 1; i < n; i++)
   {
      for (int tar = 1; tar <= target; tar++)
      {
         bool take = false;
         if (vec[i] <= tar)
            take = dp[i - 1][tar - vec[i]];
         bool noTake = dp[i - 1][tar];
         dp[i][tar] = take | noTake;
      }
   }
   int minDiff = 1e8;
   for (int i = 0; i <= target/2; i++)
   {
      if (dp[n - 1][i] == true)
      {
         minDiff=min(minDiff,abs((target - i)-i));
      }
   }
   cout << minDiff << endl;
}