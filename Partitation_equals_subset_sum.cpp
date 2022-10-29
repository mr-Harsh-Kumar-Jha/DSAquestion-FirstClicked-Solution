//Yoou are given an 'array' of 'N' ppositive integers . Your task ios to find if we can partitation the array in two subsets such that the sum of elements in both subsets is equal .

//-----------------------------------------------------------------------------

// The main key rule that i have used is that this problem is very similar to the subset target problem . Here the only catch is that the target value will be half of the sum of the elements total sum .
// there fore time complexity if the solution is O(2^n) and space complexity is O(n) which is an auxilliary stack space .

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
   vector<int>vec{2,3,3,3,6,9};
   int n = vec.size();
   int totSum = 0;
   for(int i=0;i<n;i++) totSum+=vec[i];

   if(totSum%2!=0) cout<<false<<endl;
   else {
     int target=totSum/2;
     cout<<targetSum(vec, n-1,target)<<endl;
   }
}