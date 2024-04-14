// time-complexity of the solution is :- O(n^2)
//  but this solution is more efficient  because it eliminates the need for a separate map or set to store unique triplets. Instead, it directly constructs the triplets while iterating through the array, taking advantage of the sorted nature of the input array to skip duplicate elements efficiently.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> threeSum(vector<int> &nums)
   {
      // Sort the input array
      sort(nums.begin(), nums.end());
      vector<vector<int>> ans;
      int n = nums.size();

      // Loop through each element in the array
      for (int i = 0; i < n - 2; ++i)
      {
         // remove duplicates
         if (i > 0 && nums[i] == nums[i - 1])
            continue;

         int target = -nums[i]; // Calculate the target sum for the two-pointer approach
         int left = i + 1;      // Pointer for the element to the right of the current element
         int right = n - 1;     // Pointer for the last element

         // Perform two-pointer approach
         while (left < right)
         {
            int sum = nums[left] + nums[right]; // Calculate sum of two elements

            // If sum equals target, found a triplet
            if (sum == target)
            {
               ans.push_back({nums[i], nums[left], nums[right]});
               while (left < right && nums[left] == nums[left + 1])
                  left++;
               while (left < right && nums[right] == nums[right - 1])
                  right--;
               ++left;  // Move left pointer to the right
               --right; // Move right pointer to the left
            }
            // If sum is less than target, move left pointer to the right
            else if (sum < target)
            {
               ++left;
            }
            // If sum is greater than target, move right pointer to the left
            else
            {
               --right;
            }
         }
      }

      return ans;
   }
};
