#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
   map<char, int> m;
   m['I'] = 1;
   m['V'] = 5;
   m['X'] = 10;
   m['L'] = 50;
   m['C'] = 100;
   m['D'] = 500;
   m['M'] = 1000;
   long long ans = 0;
   for (int i = 0; i < s.size(); i++)
   {
      if (m[s[i]] < m[s[i + 1]])
         ans -= m[s[i]];
      else
         ans += m[s[i]];
   }

   return ans;
}

int main()
{
   string s;
   cin>>s;
   int ans = romanToInt(s);
   cout<<ans;
}