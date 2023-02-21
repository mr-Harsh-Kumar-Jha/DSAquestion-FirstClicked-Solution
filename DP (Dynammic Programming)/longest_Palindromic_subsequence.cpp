// this is the recursive approach with dp implementation and the logic is that palindrome is that string which written in reverse fashion is same as parent string so the longest common subsequence will also be same as that of longest palindromic subsequence so we can take analogy of longest common subsequence 

#include<bits/stdc++.h>
using namespace std;

int longestPalindromicSub(string &s1 , string &s2 , int n ,int m , vector<vector<int>>&dp){
   if(n<0 || m<0) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   int take = 0;
   if(s1[n]==s2[m]) return dp[n][m] = 1+longestPalindromicSub(s1,s2,n-1,m-1,dp);
   return dp[n][m] = 0+max(longestPalindromicSub(s1,s2,n-1,m,dp),longestPalindromicSub(s1,s2,n,m-1,dp));
}

int main(){
    string s1 = "bbbab";
   string s2 = s1;
   reverse(s2.begin(), s2.end());
   int n = s1.length() , m=s2.length() ;
   vector<vector<int>>dp(n, vector<int>(m,-1));
   cout<<longestPalindromicSub(s1,s2,n-1,m-1,dp)<<endl;
}