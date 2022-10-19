//You are given an array/list Arr of N positive integers and an integer k . Your task is to check if their exist a subset in Arr with a sum equal to k .

// Note return true if their exist a subset with sum equal to k otherwise return false

//-----------------------------------------------------------------------------

// this is a recursive approach and the time complexity of the solution is O(2^n) i.e exponential and space complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

bool targetSum(vector<int>&vec,int i ,int target){
   if(target==0) return true;
   if(i==0) return vec[0]==target;
   int notTake = targetSum(vec,i-1,target);
   int take = false;
   if(target>=vec[i]) take = targetSum(vec,i-1,target-vec[i]);
   return take || notTake;
}

int main(){
   vector<int>vec{2,5,3,7,8,1,4};
   int n = vec.size();
   int target = 27;
   cout<<targetSum(vec,n-1,target)<<endl;
}