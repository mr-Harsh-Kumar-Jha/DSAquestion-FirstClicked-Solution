//time complexity of the solution is O(n*weight) and space complexity of the solution is O(n*weight)+auxilliary stck space .

#include<bits/stdc++.h>
using namespace std;

int knapSack(int w , vector<int>&wt , vector<int>&val , int n ,vector<vector<int>>&dp){
   if(w==0) return 0;
   if(n==-1) return 0;
   if(dp[n][w]!=-1) return dp[n][w];
   int noTake = 0 + knapSack(w,wt,val,n-1,dp);
   int take = INT_MIN;
   if(wt[n]<=w) take=val[n]+knapSack(w-wt[n],wt,val,n,dp);
   return dp[n][w]=max(dp[n][w],max(noTake,take));
}

int main(){
   vector<int>val{60,100,120};
   vector<int>wt{15,25,30};
   int w = 70;
   int n = val.size();
   vector<vector<int>>dp(n,vector<int>(w+1,-1));
   cout<<knapSack(w,wt,val,n-1,dp)<<endl;
}