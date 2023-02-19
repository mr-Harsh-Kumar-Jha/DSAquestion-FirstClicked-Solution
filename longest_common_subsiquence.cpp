// this is a recursive approach without using dp and the time complexity of the solution is exponential and space complexity of the solution is only auxilliary space 

#include<bits/stdc++.h>
using namespace std;

int longestCommonSub(string &s1,string &s2,int n,int m){
   if(n<0 || m<0) return 0;
   if(s1[n]==s2[m]) return  1+longestCommonSub(s1,s2,n-1,m-1);
   return 0+max(longestCommonSub(s1,s2,n-1,m),longestCommonSub(s1,s2,n,m-1));
}

int main(){
   string s1 = "defg";
   string s2 = "edgf";
   int n = s1.length();
   int m = s2.length();
   cout<<longestCommonSub(s1,s2,n-1,m-1)<<endl;
}