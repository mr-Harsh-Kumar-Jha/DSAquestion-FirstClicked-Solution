#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N];

int main(){
   memset(dp , -1 , sizeof(dp));
   int n;
   cin>>n;

   dp[0]=0;
   dp[1]=1;

   for(int i=2;i<=n;i++){
      dp[i]=dp[i-1]+dp[i-2];
   }
   cout<<dp[n]<<endl;
}