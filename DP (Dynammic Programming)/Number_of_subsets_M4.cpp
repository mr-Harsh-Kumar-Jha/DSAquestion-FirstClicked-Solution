// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of choosen elements is equal to the target number "tar".

//NOTE:
//two ways are considered different if set of indexes of elements choosen by these ways are different . Input is given in such a way that the answer can fit in a 32 bit integer .

//----------------------------------------------------------------------------------

//the time complexity of the solutuion is O(N*target) and space complexity of the solution is O(N*target) and this solution is including the case where element 0 is also present in the array.

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{0,1,2,1,3,2};
   int n = vec.size();
   int target = 4;
   vector<vector<int>>dp(n,vector<int>(target+1,0));
   for(int i=0;i<n;i++) dp[i][0]=1;
   if(vec[0]==0) dp[0][0] = 2;
   if(vec[0]!=0 && vec[0]<=target) dp[0][vec[0]]=1;
   for(int i=1;i<n;i++){
      for(int j=1;j<=target;j++){
         int noTake = dp[i-1][j];
         int take = 0;
         if(j >= vec[i]) take = dp[i-1][j-vec[i]];
         dp[i][j]=take+noTake;
      }
   }
   cout<<dp[n-1][target]<<endl;
}