// the time complexity of the above solution is O(n*m) and space complexity is O(n+m) one of the most optimized solution 

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "babgbag";
   string s2 = "bag";
   int n = s1.length();
   int m = s2.length();
   vector<int>prev(m+1, 0), curr(m+1, 0);
   for(int i=0;i<n+1;i++){
         prev[0]=1;
   }
   for(int i=1;i<=n;i++){
      curr[0] = 1;
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]){
            curr[j] = prev[j-1] + prev[j];
         }
         else curr[j] = prev[j];
      }
      prev = curr;
   }
   cout<<prev[m]<<endl;
}