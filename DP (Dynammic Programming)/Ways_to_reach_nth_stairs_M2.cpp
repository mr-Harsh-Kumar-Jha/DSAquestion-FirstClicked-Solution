//this is a tabulation technique here dp id used which is a bottom up approach .
// time complexity is O(N) and space complexity is O(n) this optimised than 1st Method ;

#include<bits/stdc++.h>
using namespace std;

int solution (int stairs ,vector<int>&dp ){
   for(int i=2;i<=stairs;i++){
         dp[i]=dp[i-1]+dp[i-2];
   }
   return dp[stairs];
}

int main(){
   int stair;
   cin>>stair;
   vector<int>dp(stair+1);
   dp[0]=1;
   dp[1]=1;
   cout<<solution(stair , dp);
}