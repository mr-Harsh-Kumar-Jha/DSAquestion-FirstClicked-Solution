//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//time complexity O(n^2)
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{

   set<char> st;
   int setSize = 0;
   int max_ans = 0;
   int i = 0;
   int j = 0;

   while (i < s.size())
   {
      st.clear();
      for (i = j; i < s.size(); i++)
      {
         if (st.find(s[i]) == st.end())
         {
            st.insert(s[i]);
            setSize = st.size();
            max_ans = max(max_ans, setSize);
         }
         else
         {
            st.erase(s[j]);
            j++;
            i = j;
            break;
         }
      }
   }

   return max_ans;
}

int main()
{
   string s;
   cin >> s;
   cout << lengthOfLongestSubstring(s) << endl;
}