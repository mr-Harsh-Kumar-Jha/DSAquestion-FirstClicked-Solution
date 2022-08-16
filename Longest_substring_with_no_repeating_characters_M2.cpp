// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// time complexity O(n)
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
   int n = s.size(), l = 0, r = 0, ans = 0; // l indicate left pointer and r indicate right pointer
   vector<int> count(256, 0);               // used to store the character with its most recent occurrence of index in an vector
   while (r < n)                            // iterate over the string till the right pointer reaches the end of the string
   {
      count[s[r]]++;          // increment the count of the character present in the right pointer
      while (count[s[r]] > 1) // if the occurence become more than 1 means the char is repeated
      {
         count[s[l]]--; // reduce the occurence of char as it might be present ahead also in the string
         l++;           // contraction of the present window till the occurence of the s[r] becomes 1
      }
      ans = max(ans, r - l + 1); // As the index starts from 0 , ans will be (right pointer-left pointer + 1)
      r++;                       // now will increment the right pointer
   }
   return ans;
}

int main()
{
   string s;
   cin >> s;
   cout << lengthOfLongestSubstring(s) << endl;
}