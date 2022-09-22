// this is a Tabular Approach (Bottom Up approach) with time complexity O(n*k) and space complexity O(n);

#include <bits/stdc++.h>
using namespace std;

int powJump(int stairs, vector<int> &pow, vector<int> &dp, int k)
{
   int jumps;
   int mins;
   for (int i = 1; i <= stairs; i++)
   {
      mins=INT_MAX;
      for (int j = 1; j <= k; j++)
      {
         if (i - j >= 0)
         {
            jumps = dp[i-j] + abs(pow[stairs] - pow[stairs - i]);
         }
         else
         {
            break;
         }
         mins = min(mins,jumps);
      }
      dp[i] = mins;
   }
   return dp[stairs-1];
}

int main()
{
   vector<int> pow{10, 30, 20, 60, 40, 30};
   vector<int> dp(pow.size(), 0);
   int k;
   cin >> k;
   powJump(pow.size() - 1, pow, dp, k);
   cout << dp[pow.size()-1] << endl;
}