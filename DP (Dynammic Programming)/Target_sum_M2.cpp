#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,2,1};
   int n = vec.size();
   int target = 0;
   int total = 0;

   for(int i=0;i<n;i++){
      total+=vec[i];
   }

     if((total-target)%2==0 && (total-target)>=0){
      int targetToSearched = (total-target)/2;
      vector<vector<int>>dp(n,vector<int>(targetToSearched+1,0));
      if(vec[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
      else dp[0][0] = 1;  // 1 case - not pick

      if(vec[0]!=0 && vec[0]<=targetToSearched){
         dp[0][vec[0]] = 1; 
      }

      for(int i=1;i<n;i++){
         for(int j=0;j<=targetToSearched;j++){
            int take = 0;
            if(vec[i]<=j) take = dp[i-1][j-vec[i]];
            int noTake = dp[i-1][j];
            dp[i][j] = take+noTake;
         }
      }
      cout<<dp[n-1][targetToSearched]<<endl;
     }
     else
        cout<<0<<endl;
     return 0;
}