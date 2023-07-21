#include<bits/stdc++.h>
using namespace std;

int burstBalloons(vector<int>&vec,int i,int j, vector<vector<int>>&dp){
   if(i>j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   int mini = INT_MIN;
   for(int ind = i;ind<=j;ind++){
      int cost = (vec[i-1]*vec[ind]*vec[j+1]) + burstBalloons(vec,i,ind-1,dp) + burstBalloons(vec, ind+1,j,dp);
      mini = max(mini,cost);
   }
   return dp[i][j]=mini;
}

int main(){
   vector<int>vec{1,5};
   int n = vec.size();
   vec.insert(vec.begin(), 1);
   vec.push_back(1);
   vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
   cout<<burstBalloons(vec,1,n,dp)<<endl;
}