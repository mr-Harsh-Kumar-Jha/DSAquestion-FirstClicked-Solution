#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroLocation = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeroLocation += 1;
            }else{
                if(zeroLocation!=0){
                    nums[i-zeroLocation] = nums[i];
                    nums[i]=0;
                }
            }
        }
    }
};