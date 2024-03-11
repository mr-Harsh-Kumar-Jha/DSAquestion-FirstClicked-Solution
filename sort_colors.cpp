// The Dutch National Flag algorithm is called one-pass because it sorts the array in a single pass through the elements. The time complexity of the algorithm is O(n), where n is the size of the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};