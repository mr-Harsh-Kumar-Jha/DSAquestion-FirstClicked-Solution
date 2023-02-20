//this is a space optimized solution and the time complexity is O(n*m) and space complexity is O(n+m);

#include<bits/stdc++.h>
using namespace std;

int main() {
      vector<int> nums1 = {1,2,3,2,1}, nums2={3,2,1,4,7};
      int n = nums1.size() , m = nums2.size() , ans = 0;
      vector<int>prev(n+1 , 0) , curr(m+1 ,0);
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            if(nums1[i-1]==nums2[j-1]){
               curr[j] = 1 + prev[j-1];
               ans=max(ans, curr[j]);
            }
            else curr[j]=0;
         }
           prev = curr;
      }
      cout<< ans <<endl;
}