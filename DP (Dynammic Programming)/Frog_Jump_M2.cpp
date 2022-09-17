// this is a bottom up approach its time complexity is O(n) and space complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<int>pow{10,30,20,60,40,20,10};
   vector<int> dp(pow.size(),0);
   dp[0]=0;
   for(int i=1;i<pow.size();i++){
      int left = dp[i-1]+abs(pow[i]-pow[i-1]);
      int right = INT_MAX;
      if(i>1)
        right = dp[i-2]+abs(pow[i]-pow[i-2]);
      dp[i]=min(left,right);
      cout<<dp[i]<<" ";
   }
   cout<<dp[pow.size()-1];
}