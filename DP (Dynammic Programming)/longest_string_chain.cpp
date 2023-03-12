#include<bits/stdc++.h>
using namespace std;

const bool comp(string &s1, string &s2){
   return s1.size() < s2.size();
}

bool check(string &s1 , string &s2){
   if(s1.size() != s2.size()+1) return false;
   int n = s1.size(),m = s2.size();
   int i = 0,j=0;
   while(i<n){
      if(s1[i]==s2[j]){
            i++;
            j++;
      }
      else i++;
   }
   if(i == s1.size() && j==s2.size()) return true;
   else return false;
}

int main(){
   vector<string>vec{"a","b","ba","bca","bda","bdca"};
   int n = vec.size();
   sort(vec.begin(), vec.end(), comp);
   vector<int>dp(n,1);
   int maxi = 1;
   for(int i = 0;i<n;i++){
      for(int j = 0; j<i; j++){
         if(check(vec[i] , vec[j]) && 1+dp[j]>dp[i]){
            dp[i] = 1+dp[j];
         }
      }
     maxi=max(maxi,dp[i]);
   }
   cout<<maxi<<endl;
}