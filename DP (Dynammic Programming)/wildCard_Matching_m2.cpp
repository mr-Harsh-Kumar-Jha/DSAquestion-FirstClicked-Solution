// time complexity is O(n*m) and space complexity is O(n+m)

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1  = "aa";
   string s2 = "*b";
   int n = s1.length();
   int m = s2.length();
   vector<bool>prev(m+1 , 0), curr(m+1,0);
   prev[0] = true;
   for(int i = 1;i<=m;i++){
      bool flag = true;
       for(int j=1;j<=i;j++){
         if(s2[j-1]!='*') {
            flag = false;
            break;
         }
      }
      prev[i] = flag;
   }
   for(int i=1;i<=n;i++){
      curr[0] = false;
      for(int j = 1;j<=m;j++){
         if(s1[i-1]==s2[j-1] || s2[j-1]=='?') curr[j] = prev[j-1];
         else if(s2[j-1]=='*'){
            curr[j] = (curr[j-1] | prev[j]);
         }
         else curr[j] = false;
      }
      prev = curr;
   }
   cout<<prev[m]<<endl;
}