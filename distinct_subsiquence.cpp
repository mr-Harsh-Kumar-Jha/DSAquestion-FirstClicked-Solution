#include<bits/stdc++.h>
using namespace std;

int distinctSubsiquence(string &s1 , string &s2 , int n, int m){
   if(m<0) return 1;
   if(n<0) return 0;

   if(s1[n]==s2[m]) return distinctSubsiquence(s1,s2,n-1,m-1) + distinctSubsiquence(s1,s2,n-1,m);
   else return distinctSubsiquence(s1,s2,n-1,m);
}

int main(){
   string s1 = "babgbag";
   string s2 = "bag";
   int n = s1.length();
   int m = s2.length();
   cout<<distinctSubsiquence(s1,s2,n-1,m-1)<<endl;
}