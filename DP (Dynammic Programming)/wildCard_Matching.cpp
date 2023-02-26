// the logic is very simple as u can see we are said that if '?' occurs then it can replace any one character , whereas when '*' occurs then it can replace sequence of character and so when there is '*' present then we are considering 2 cases like either we can keep it un matched or we can match it one by one with all characters  , and we will take 'or' because by considering any sequence we can get our ans so if any one will be true we will can match this sequence .

// the time complexity of the solution is O(n*m) and space complexity is O(n* m)+O(n+m);

#include<bits/stdc++.h>
using namespace std;

bool wildcardMatch(string &s1 , string &s2 , int n , int m, vector<vector<int>>&dp){
   if(n>=0 && m<0) return false;
   if(n<0 && m<0) return true;
   if(m>=0 && n<0){
      for(int i=0;i<=m;i++){
         if(s2[i]!='*') return false;
      }
      return true;
   }
   if(dp[n][m]!=-1) return dp[n][m];

   if(s1[n]==s2[m] || s2[m]=='?') return dp[n][m] = wildcardMatch(s1,s2,n-1,m-1, dp);
   if(s2[m]=='*'){
      return dp[n][m] = (wildcardMatch(s1,s2,n,m-1, dp)  | wildcardMatch(s1,s2,n-1,m, dp));
   }
   return dp[n][m] = false;
}

int main(){
   string s1  = "cb";
   string s2 = "?b";
   int n = s1.length();
   int m = s2.length();
   vector<vector<int>>dp(n , vector<int>(m,-1));
   if(wildcardMatch(s1,s2,n-1,m-1 , dp)==0) cout<<"false"<<endl;
   else cout<<"true"<<endl;
}