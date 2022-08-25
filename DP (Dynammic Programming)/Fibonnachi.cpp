//top Down Approach

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int dp[N] ;

int fib(int n){
   if(n==0) return 0; // base condition
   if(n==1) return 1; // base condition

   if(dp[n]!=-1) {
      cout<<dp[n]<<" ";
      return dp[n]; // if the n is already visited so returning the ans at that nth position .
   }

   return dp[n]= (fib(n-1)+fib(n-2));  // recurcive call
}

int main(){
   int n;
   cin>>n;
   memset(dp ,-1,sizeof(dp));
   cout<<fib(n)<<endl;
}