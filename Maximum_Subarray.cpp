// Time Complexity : O(n)
//  my Logic: My logic is that whenever we add an element to our sum  the sum must always be greater than the number added (this will hold for every case else the number itself will be greatest and our subarray searching will start from that element)

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