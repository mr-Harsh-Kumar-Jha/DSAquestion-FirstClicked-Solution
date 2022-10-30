//Yoou are given an 'array' of 'N' ppositive integers . Your task ios to find if we can partitation the array in two subsets such that the sum of elements in both subsets is equal .

//-----------------------------------------------------------------------------

// The main key rule that i have used is that this problem is very similar to the subset target problem . Here the only catch is that the target value will be half of the sum of the elements total sum .
// the time complexity of the solution is O(n*target) and space complexity of the solution is O(target);

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{2,3,3,3,6,7};
   int n = vec.size();
   int totSum = 0;
   for(int i=0;i<n;i++) totSum+=vec[i];
   if(totSum%2!=0) cout<<0<<endl;
   else{
      int target = totSum/2;
      vector<bool>dp(target,0);
      dp[0]=true;
      dp[vec[0]] = true;
      for(int i=1;i<n;i++){
         vector<bool>curr(target,0);
         dp[0]=true;
         for(int tar = 1; tar<=target; tar++){
            int take = false;
            if(vec[i]<=tar) take = dp[tar-vec[i]];
            int noTake = dp[tar];
            curr[tar]= take|noTake;
         }
         dp=curr;
      }
      cout<<dp[target]<<endl;
   }
}