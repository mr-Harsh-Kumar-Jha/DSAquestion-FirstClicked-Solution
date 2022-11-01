// You are given an array containing N non-negative integers . Your Task is to Partition this array into two subsets such that the absolute difference between subset sums is minimum .

// Your task is to find the minimum absolute difference considering any valid division of the array element .

//---------------------------------------------------------------------------

// time complexity of the solution is O(n*target) and space complexity is            O(target) .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,4,3,4};
   int n = vec.size();
   int totSum = 0;
   for(int i=0;i<n;i++) totSum+=vec[i];
      vector<bool>dp(totSum,0);
      dp[0]=true;
      dp[vec[0]] = true;
      for(int i=1;i<n;i++){
         vector<bool>curr(totSum,0);
         dp[0]=true;
         for(int tar = 1; tar<=totSum; tar++){
            bool take = false;
            if(vec[i]<=tar) take = dp[tar-vec[i]];
            bool noTake = dp[tar];
            curr[tar]= take|noTake;
         }
         dp=curr;
      }
      int minDiff = 1e8;
      for (int i = 0; i <= totSum/2; i++)
      {
         if (dp[i] == true)
         {
            minDiff=min(minDiff,abs((totSum - i)-i));
         }
      }
      cout << minDiff << endl;
}