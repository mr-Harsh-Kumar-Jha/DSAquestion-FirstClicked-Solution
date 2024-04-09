// time complexity is O(nlog(n))
//Approach:- The approach is very simple as you can see we need to find  elements which appear more than n/2 times will have its presence in the n/2th position. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};