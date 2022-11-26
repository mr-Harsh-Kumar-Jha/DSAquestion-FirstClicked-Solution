#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s = "abcbaxcbavahbdcab";
   string subS = "abc";
   int n = s.size();
   int k = subS.size(), start = 0, end = 0;
   int ans=0;
   map<char, int> m;
   for (int i = 0; i < k; i++){
      m[subS[i]]++;
   }
   int count = m.size();
   while (end < n){
       if (m.find(s[end]) != m.end()){
            m[s[end]]--;
            if (m[s[end]] == 0) count--;
      }
      if ((end - start+1) <k) end++;
      else if((end-start+1)==k){
         if (count == 0) ans++;
         if (m.find(s[start]) != m.end()){
            m[s[start]]++;
            if (m[s[start]] == 1) count++;
         }
         start++;
         // if (m.find(s[end]) != m.end()){
         //    m[s[end]]--;
         //    if (m[s[end]] == 0)
         //       count--;
         //    // else if(m[s[end]]<0) count++;
         // }
         end++;
      }
   }
   cout << ans<< endl;
   // cout<<ans<<endl;
}