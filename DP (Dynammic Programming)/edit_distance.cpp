// this is a dp based approach and the solution to this problem is very easy as we are given that we are allowed to perform all the three operation insertion , deletion , replacing the characters .

// btw the time complexity of the solution  is O(n*m) and space complexity od the solution is O(n*m)+O(n+m) .

#include<bits/stdc++.h>
using namespace std;

int editDist(string &s1 , string &s2 , int n , int m , vector<vector<int>>&dp){
   if(n<0) return m+1;  // if string 1 is exhausted then there is simple thing how many letters needs to be inserted to make it look like string 2 it is same as m+1 characters
   if(m<0) return n+1; // if string 2 is exhausted then there is simple thing that we have matched with our desired string now we need to remove all elements thich is extra in string s1 i.e will be equal to n+1 .
   if(dp[n][m]!=-1) return dp[n][m];
   if(s1[n]==s2[m]) return dp[n][m] = editDist(s1,s2,n-1,m-1, dp);
   else return dp[n][m] = min((1 + editDist(s1,s2,n,m-1,dp)), min((1+editDist(s1,s2,n-1,m,dp)), (1+editDist(s1,s2,n-1,m-1,dp)))); // first part is for insertion , second part is for deletion and third part is for deletion when u inset things u dont need to care about
}

int main(){
   string s1 = "horse" , s2 = "ros";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n , vector<int>(m,-1));
   cout<<editDist(s1,s2,n-1,m-1 , dp)<<endl;
}