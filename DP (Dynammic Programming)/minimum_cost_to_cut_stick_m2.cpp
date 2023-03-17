// time complexity is O(N^3) and space complexity is O(size^2) here no stack space is required as we have not used recurssion .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{5,6,1,4,2};
   int size = vec.size();
   int n = 9;
   vec.insert(vec.begin(),0);
   vec.push_back(n);
   sort(vec.begin(),vec.end());
   vector<vector<int>>dp(size+2,vector<int>(size+2,0));
   for(int i = size;i>=1;i--){
      for(int j = 1;j<=size;j++){
         if(i>j) continue;
         int mini = INT_MAX;
         for(int k = i;k<=j;k++){
            int ans =vec[j+1]-vec[i-1] + dp[i][k-1] + dp[k+1][j];
            mini = min(mini,ans);
         }
         dp[i][j] = mini;
      }
   }
   cout<<dp[1][size]<<endl;
}