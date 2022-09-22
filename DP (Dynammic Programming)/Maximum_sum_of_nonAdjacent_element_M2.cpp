// this is a  bottom up approach and the time complexity is O(n) and space complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

int maxSum(int ind,vector<int>&vec,vector<int>&dp){
     dp[0]=vec[0];
     int prev =0;
     for(int i=1;i<=ind;i++){
       int take = vec[i];
       if(i>1) take+=dp[i-2];
       int nTake = 0+dp[i-1];
       dp[i]=max(take,nTake);
     }
     return dp[ind];
}

int main(){
   vector<int>vec{1,3,2,9,6},dp(vec.size(),0);
   cout<<maxSum(vec.size()-1,vec,dp);
   return 0;
}