
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//-----------------------------------------------------------------------------------

// This is a space optimization code in DP. whose time complexity O(n)+O(n) and space complexity O(1);

#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> vec{2, 4, 5, 1, 6};
   long long int prev2 = 0;
   long long int prev = vec[0];
   for (int i = 1; i < vec.size() - 1; i++)
   {
      long long int take = vec[i];
      if (i > 1)
         take += prev2;
      long long int nTake = 0 + prev;
      long long int curri = max(take, nTake);
      prev2 = prev;
      prev = curri;
   }
   long long int prev1 = vec[1];
   prev2 = 0;
   for (int i = 2; i < vec.size(); i++)
   {
      long long int take = vec[i];
      if (i > 2)
         take += prev2;
      long long int nTake = 0 + prev1;
      long long int curri = max(take, nTake);
      prev2 = prev1;
      prev1 = curri;
   }
   cout << max(prev1, prev) << endl;
}