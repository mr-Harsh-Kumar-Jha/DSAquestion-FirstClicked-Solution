// Time Complexity: O(n^3)
// the approach :- It is very simple approach as it is solved using two pointers .

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long int sum = 0;
        int length = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>>ans;
        set<vector<int>>set;

        for(int i=0; i<(length-3); ++i){
            sum = nums[i];
            for(int j=i+1; j<(length-2); j++){
                sum += nums[j];
                int k = j+1;
                int l = length-1;
                while(k<l){
                    sum = sum + nums[k] + nums[l];
                    if(sum > target){
                        sum = sum - nums[k] - nums[l];
                        l--;
                    }else if(sum < target){
                        sum = sum - nums[k] - nums[l];
                        k++;
                    }else{
                        set.insert({nums[i], nums[j], nums[k], nums[l]});
                        sum = sum - nums[k] - nums[l];
                        k++;
                        l--;
                    }
                }
                sum-=nums[j];
            }
        }

        for(auto it:set){
            ans.push_back(it);
        }

        return ans;
    }
};