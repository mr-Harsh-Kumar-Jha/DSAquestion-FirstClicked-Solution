#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,k=1;
        int number = nums[0];
        while(i<nums.size()){
            if(nums[i]!=number){
                nums[k] = nums[i];
                k++;
            }
            number = nums[i];
            i++;
        }

        return k;
    }
};