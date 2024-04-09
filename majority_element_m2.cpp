// time complexity :- O(n)
// Approach :- Moore Algorithm states that those elements which are present more than n/2 times must have repeating occurance or last  occurance so count element variable will contain  this repeated variable as count will never be zero .

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;

        for(int i=0;i<nums.size();i++){
            if(count == 0){
                element = nums[i];
                count++;
            }else if(element==nums[i]){
                count++;
            }else{
                count--;
            }
        }

        return element;
    }
};