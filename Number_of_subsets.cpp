// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of choosen elements is equal to the target number "tar".

//NOTE:
//two ways are considered different if set of indexes of elements choosen by these ways are different . Input is given in such a way that the answer can fit in a 32 bit integer .

//----------------------------------------------------------------------------------

//the time complexity of the solution is O(2^n) and space complexity is auxilliary space .

#include<bits/stdc++.h>
using namespace std;

int countSubset(vector<int>&vec , int n , int target){
   if(n == 0) return vec[0]==target;
   if(target==0) return 1;
   int notTake = countSubset(vec,n-1,target);
   int take = 0;
   if(vec[n] <= target)
      take = countSubset(vec,n-1,target-vec[n]);
   return  notTake+take;
}

int main(){
   vector<int>vec{1,2,2,3};
   int n = vec.size();
   int target = 3;
   cout<<countSubset(vec,n-1,target)<<endl;
}