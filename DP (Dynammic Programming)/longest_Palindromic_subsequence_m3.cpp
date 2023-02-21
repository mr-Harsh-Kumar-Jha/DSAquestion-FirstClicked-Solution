// there is a very simple approach as we can see palidrome is nothing but if we reverse the string then also the newly formed string must be equal to parent string , so if we reverse the string and store it and try to find longest common subsequence , we will get the result .

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s1 = "bbbab";
   string s2 = s1;
   reverse(s2.begin(), s2.end());
   int n = s1.length() , m=s2.length() , ans = 0;
   vector<int>prev(m+1,0) , curr(m+1,0);

   for(int i=1 ; i<=n; i++){
      for(int j=1;j<=m;j++){
         if(s1[i-1]==s2[j-1]) curr[j] = 1+prev[j-1];
         else curr[j] = max(prev[ j] , curr[j-1]);
      }
      prev = curr;
   }
   cout<<prev[m]<<endl;
}