//Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

//Now consider if some obstacles are added to the grids. How many unique paths would there be?

//-----------------------------------------------------------------------------------

// this is a bottom up approach and the time complexity ofthe solution is O(n*m) and space complexity is O(n*m)

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>>vec{
      {0,0,0},
      {0,0,0},
      {1,0,0},
   },dp(vec.size(),vector<int>(vec[0].size(),-1));
   for(int i=0;i<vec.size();i++){
      for(int j=0;j<vec[0].size();j++){
         if(i==0 && j==0) dp[i][j]=1;
         else if(vec[i][j]==1) dp[i][j] = 0;
         else{
            int up = 0,left =0;
            if(i>0) up=dp[i-1][j];
            if(j>0) left = dp[i][j-1];
            dp[i][j]=up+left;
         }
      }
   }
  cout<<dp[vec.size()-1][vec[0].size()-1]<<endl;
}