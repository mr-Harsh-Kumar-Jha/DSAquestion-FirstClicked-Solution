#include<bits/stdc++.h>
using namespace std;

int powJump(int stairs , vector<int>&pow,vector<int>&dp,int k){
   if(stairs==0) return 0;
   if(stairs<0) return 0;
   if(dp[stairs]!=-1) return dp[stairs];
   int jumps ;
   int mins = INT_MAX;
   for(int i=1;i<=k;i++){
      if(stairs-i>=0){
         jumps = powJump(stairs-i,pow,dp,k)+abs(pow[stairs]-pow[stairs-i]);
      }
      else{
         break;
      }
      mins=min(mins,jumps);
   }
   return dp[stairs]= mins;
}

int main(){
   vector<int>pow{10,30,20,60,40,30};
   vector<int>dp(pow.size(),-1);
   int k;
   cin>>k;
   powJump(pow.size()-1,pow,dp,k);
   cout<<dp[pow.size()-1]<<endl;
}