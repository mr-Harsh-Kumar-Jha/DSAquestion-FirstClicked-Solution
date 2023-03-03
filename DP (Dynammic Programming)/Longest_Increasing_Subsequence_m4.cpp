#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<int>dp(n,1);
   for(int i=0;i<n;i++){
      for(int j=0;j<=i-1;j++) if(vec[i]>vec[j]) dp[i] = max(dp[i],1+dp[j]);
   }
   int ans = *max_element (dp.begin(), dp.end());
   cout<<ans<<endl;
}