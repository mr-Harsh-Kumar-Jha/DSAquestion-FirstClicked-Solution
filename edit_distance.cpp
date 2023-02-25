// this is a normal recursive approach and it can be optimized using dp , kindly refer to the dp section .
// btw the time complexity of the solution is exponential almost of the range 3^n+m and space complexity is O(n+m) which is an auxilliary space .

#include<bits/stdc++.h>
using namespace std;

int editDist(string &s1 , string &s2 , int n , int m){
   if(n<0) return m+1;
   if(m<0) return n+1;

   if(s1[n]==s2[m]) return editDist(s1,s2,n-1,m-1);
   else return min((1 + editDist(s1,s2,n,m-1)), min((1+editDist(s1,s2,n-1,m)), (1+editDist(s1,s2,n-1,m-1))));
}

int main(){
   string s1 = "horse" , s2 = "ros";
   int n = s1.length();
   int m = s2.length();
   cout<<editDist(s1,s2,n-1,m-1)<<endl;
}