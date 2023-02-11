// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// =================================================================================

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
      int i = 0, j = 0 , sum=0 , sum2=INT_MIN;
      while(j<nums.size()){
         sum+=nums[j];
         if((j-i+1)<k){
             j++;
         }
         else if((j-i+1)==k){
               sum2 = max(sum2,sum);
               sum-=nums[i];
               i++;
               j++;
          }
      }
      return (double)sum2/(double)k;
}

int main(){
   vector<int>nums{1,12,-5,-6,50,3};
   int k = 4;
   cout<<findMaxAverage( nums,  k)<<endl;
}