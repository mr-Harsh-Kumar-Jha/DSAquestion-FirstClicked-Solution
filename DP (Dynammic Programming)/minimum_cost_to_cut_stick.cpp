// time complexity is O(N^3) and space complexity is O(size^2)+O(size)

#include<bits/stdc++.h>
using namespace std;

int minCost(int i , int j, vector<int>&vec ,vector<vector<int>>&dp){
   if(i>j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   int mini = INT_MAX;
   for(int k = i;k<=j;k++){
      int ans =vec[j+1]-vec[i-1]+minCost(i,k-1,vec,dp)+minCost(k+1,j,vec,dp);
      mini = min(mini,ans);
   }
   return dp[i][j] = mini;
}

int main(){
   vector<int>vec{5,6,1,4,2};
    int size = vec.size();
   int n = 9;
   vec.insert(vec.begin(),0);
   vec.push_back(n);
   sort(vec.begin(),vec.end());
   vector<vector<int>>dp(size+1,vector<int>(size+1,-1));
   cout<<minCost(1,size,vec,dp)<<endl;
}