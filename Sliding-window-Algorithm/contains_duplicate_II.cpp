

#include<bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int n = nums.size();
      int i = 0 ,j = 0;
      unordered_map<int,int>m;
      while(j<n){
            if(j-i <= k){
               if(m.find(nums[j])!=m.end()){
                  return true;
               }
               else{
                  m[nums[j]]++;
                  j++;
               }
            }
            else{
               m.erase(nums[i]);
               i++;
            }
      }
      return false;
}

int main(){
   vector<int>nums{1,2,3,1};
   int k = 3;
   cout<<containsNearbyDuplicate(nums, k)<<endl;
}