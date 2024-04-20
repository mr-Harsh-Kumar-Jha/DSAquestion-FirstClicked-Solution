//  Time Complexity :- O(n^3)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;

        for(int i=0; i<(length-3); i++){
          // This is the condition to stop repeatable elements to be picked up
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j=i+1; j<(length-2); j++){
               // This is the condition to stop repeatable elements to be picked up
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j+1;
                int l = length-1;
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target){
                        l--;
                    }else if(sum < target){
                        k++;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int temp_k = nums[k];
                        int temp_l = nums[l];

                        // these while loops are used to keep track of unrepeated elements to be picked up
                        while (k < nums.size() && nums[k] == temp_k) {
                            k++;
                        }

                        while (l > 0 && nums[l] == temp_l) {
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};