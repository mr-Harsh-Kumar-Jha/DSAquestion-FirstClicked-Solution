// Time complexity :- O(n^2)
//  As Inside the nested loop, there's a sort operation applied to the vec vector. The size of this vector is always 3, so sorting it will take O(3 * log(3)), which can be considered O(1) because it's a constant.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> threeSum(vector<int> &nums)
   {
      vector<vector<int>> ans;
      unordered_map<int, int> map;
      set<vector<int>> sets;
      for (int i = 0; i < nums.size(); i++)
      {
         map[nums[i]]++;
      }
      int sum = 0;
      for (auto its : map)
      {
         sum = its.first;
         map[its.first]--;
         for (auto it : map)
         {
            if (it.second == 0)
            {
               continue;
            }
            sum += it.first;
            map[it.first]--;

            int diff = 0 - sum;
            if (map.find(diff) != map.end() && map[diff] != 0 && (its.first + it.first + diff) == 0)
            {
               vector<int> vec = {its.first, it.first, diff};
               sort(vec.begin(), vec.end());
               sets.insert(vec);
               map[it.first]++;
               sum -= it.first;
            }
            else
            {
               map[it.first]++;
               sum -= it.first;
            }
         }
         sum = 0;
         map[its.first]++;
      }

      for (auto it : sets)
      {
         ans.push_back(it);
      }

      return ans;
   }
};