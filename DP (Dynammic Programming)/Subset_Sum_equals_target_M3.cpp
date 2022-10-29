//You are given an array/list Arr of N positive integers and an integer k . Your task is to check if their exist a subsequences in Arr with a sum equal to k .

// Note return true if their exist a subset with sum equal to k otherwise return false

//-----------------------------------------------------------------------------

//Time complexity of the solution is O(n*target) and space complexity of the solution is O(target)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{2,3,1,1};
   int n = vec.size();
   int target = 8;
   vector<bool>prev(target+1,0);
   prev[0]=true;
   prev[vec[0]]=true;
   for(int i=1;i<=n-1;i++){
      vector<bool>curr(target+1,0);
      curr[0]=true;
      for(int tar = 1;tar<=target;tar++){
         int take = false;
         if(tar >= vec[i]) take = prev[tar-vec[i]];
         int notTake = prev[tar];
         curr[tar]= take | notTake;
      }
      prev = curr;
   }
   cout<<prev[target]<<endl;
}