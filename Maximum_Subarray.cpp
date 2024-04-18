// Time Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>=nums[i]){
                sum+=nums[i];
            }else{
                sum = nums[i];
            }
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};