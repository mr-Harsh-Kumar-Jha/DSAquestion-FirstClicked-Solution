// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of choosen elements is equal to the target number "tar".

//NOTE:
//two ways are considered different if set of indexes of elements choosen by these ways are different . Input is given in such a way that the answer can fit in a 32 bit integer .

//----------------------------------------------------------------------------------

//the time complexity of the solutuion is O(N*target) and space complexity of the solution is O(N*target)+auxilliary space;

#include<bits/stdc++.h>
using namespace std;

int countSub(vector<int>&vec,int n,int target,vector<vector<int>>&dp){
   if(target == 0) return 1;
   if(n==0) return vec[0]==target;
   if(dp[n][target]!=-1) return dp[n][target];
   int noTake = countSub(vec,n-1,target,dp);
   int take = 0;
   if(target >= vec[n]) take = countSub(vec,n-1,target-vec[n],dp);
   return dp[n][target] = take+noTake;
}

int main(){
   vector<int>vec{1,2,2,3};
   int n = vec.size();
   int target = 4;
   vector<vector<int>>dp(n,vector<int>(target+1,-1));
   cout<<countSub(vec,n-1,target,dp);
}