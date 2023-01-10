//https://leetcode.com/problems/first-missing-positive/description/

//this is a very optimized solution for the above question where the time complexity is O(n) and space complexity is O(1). using cyclic sort we can achieve it .

#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
      for(int i=0;i<nums.size();){
         if(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]) swap(nums[i],nums[nums[i]-1]);
         else i++;
      }
      for(int i=0;i<nums.size();i++){
         if(nums[i]!=i+1){
            return i+1;
         }
      }
      return nums.size()+1 ;
}

int main(){
   vector<int>vec{-1, 4,2,1,-4};
   cout<<firstMissingPositive(vec)<<endl;
}