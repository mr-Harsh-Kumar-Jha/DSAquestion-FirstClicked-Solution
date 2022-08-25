#include <bits/stdc++.h>
using namespace std;
vector<int> DP(46,-1);

int climbStairs(int n)
{
   if (n == 0)
      return 1;
   if (n < 0)
      return 0;
   if (DP[n] != -1)
      return DP[n];
   return DP[n] = climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
   int n;
   cin>>n;
   cout<<climbStairs(n)<<endl;
}