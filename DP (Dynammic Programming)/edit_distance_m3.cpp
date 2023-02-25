// this is an optimised solution and the time complexity is O(n*m) and space complexity is O(n+m) 

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "horse" , s2 = "ros";
   int n = s1.length();
   int m = s2.length();
   vector<int>prev(m+1 , 0) , curr(m+1 , 0);
   for(int i=0;i<=m;i++) prev[i] = i;
   for(int i=1;i<=n;i++){
      curr[0] = i;
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) curr[j] = prev[j-1];
         else curr[j] = min((1+curr[j-1]) , min((1+prev[j]), (1+prev[j-1])));
      }
      prev = curr;
   }
   cout<<prev[m]<<endl;
}