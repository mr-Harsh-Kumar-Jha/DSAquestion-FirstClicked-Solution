//Given a grid of size m * n, let us assume you are starting at (1, 1) and your goal is to reach (m, n). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

//Now consider if some obstacles are added to the grids. How many unique paths would there be?

//-----------------------------------------------------------------------------------

// this is a space optimization  approach and the time complexity ofthe solution is O(n*m) and space complexity is O(m);

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>>vec{
      {0,0,0},
      {0,1,0},
      {0,0,0},
   };
   int n=vec.size(),m=vec[0].size();
   vector<int>prev(m,0);
   for(int i=0;i<vec.size();i++){
      vector<int>curr(m,0);
      for(int j=0;j<vec[0].size();j++){
         if(i==0 && j==0) curr[j]=1; // base case
         else if(vec[i][j]==1) curr[j] = 0;  // condition for metting the condition where there is obstacle in the path .
         else{
            int up = 0,left =0;
            if(i>0) up=prev[j];
            if(j>0) left = curr[j-1];
            curr[j]=up+left;
         }
      }
      prev=curr;
   }
  cout<<prev[m-1]<<endl;
}