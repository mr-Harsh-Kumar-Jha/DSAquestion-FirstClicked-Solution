// this is the brute force solution
// Time complexity:- O(n^4)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long int sum = 0;
        int length = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>set;
        for(int i=0; i<(length-3); ++i){
            sum = nums[i];
            for(int j=i+1; j<(length-2); j++){
                sum += nums[j];
                for(int k = j+1; k<(length-1);k++){
                    sum+=nums[k];
                    for(int l = k+1; l<length; l++){
                        sum+=nums[l];
                        if(sum==target){
                            vector<int>vec = {nums[i], nums[j], nums[k], nums[l]};
                            sort(vec.begin(), vec.end());
                            set.insert(vec);
                        }
                        sum-=nums[l];
                    }
                    sum-=nums[k];
                }
                sum-=nums[j];
            }
            sum-=nums[i];
        }

        for(auto it:set){
            ans.push_back(it);
        }

        return ans;
    }
};