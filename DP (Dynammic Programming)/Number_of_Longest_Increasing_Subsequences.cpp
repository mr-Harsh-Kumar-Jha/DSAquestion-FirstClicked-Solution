#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,3,5,4,7};
   int n = vec.size();
   int maxi = 1;
   vector<int>dp(n,1) , count(n,1);
   for(int i = 0;i<n;i++){
      for(int j = 0;j<i;j++){
         if(vec[i]>vec[j] && 1+dp[j] > dp[i]){
            dp[i] = 1+dp[j];
            count[i] = count[j];
         }
         else if(vec[i]>vec[j] && 1+dp[j]==dp[i]){
            count[i]+=count[j];
         }
      }
      maxi = max(maxi,dp[i]);
   }
   int ans=0;
   for(int i=0;i<n;i++){  // this is used to handle case when every element of the array is same .
      if(dp[i]==maxi) ans+=count[i];
   }
   cout<<ans<<endl;
}