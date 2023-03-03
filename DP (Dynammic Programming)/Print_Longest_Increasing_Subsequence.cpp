#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<int>dp(n,1), hash(n,0);
   int prevIndex,maxi=INT_MIN;
   for(int i=0;i<n;i++){
      hash[i]=i;
      for(int j=0;j<=i-1;j++){
         if(vec[i]>vec[j] && 1+dp[j]>dp[j]){
            dp[i]  = 1+dp[j];
            hash[i] = j;
         }
      }
      if(maxi<dp[i]){
         maxi = dp[i];
         prevIndex = i;
      }
   }
   vector<int>ans;
   while(vec[prevIndex]!=prevIndex){
       ans.push_back(vec[prevIndex]);
       prevIndex = hash[prevIndex];
   }
   for(int i=ans.size()-1;i>=0;i--){
      cout<<ans[i]<<endl;
   }
}