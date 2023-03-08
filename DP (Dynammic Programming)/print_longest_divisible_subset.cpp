#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{4,1,16,7,64,32};
   int n = vec.size();
   sort(vec.begin(),vec.end());
   vector<int>dp(n,1) , hash(n,0);
   int maxi = INT_MIN , prev ;
   for(int i = 0;i<n;i++){
      hash[i] = i;
      for(int j = 0;j<=i-1;j++){
         if(vec[i]%vec[j]==0 && 1+dp[j]>dp[j]){
            dp[i] = 1+dp[j];
            hash[i] = j;
         }
      }
      if(maxi<dp[i]){
         maxi = dp[i];
         prev = i;
      }
   }
   vector<int>ans;
   ans.push_back(vec[prev]);
   while(hash[prev]!=prev){
       prev = hash[prev];
       ans.push_back(vec[prev]);
   }
   for(int i=ans.size()-1;i>=0;i--){
      cout<<ans[i]<<" ";
   }
   cout<<endl;
}