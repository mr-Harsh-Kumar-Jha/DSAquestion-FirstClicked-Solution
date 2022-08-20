// time complexity : O(n) and space complexity O(n)
// https://leetcode.com/problems/longest-palindrome

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
   map<char, int> m;
   int count = 0;
   int count_one_presence = 0;
   for (size_t i = 0; i < s.length(); i++)
   {
      m[s[i]]++;
   }
   for (auto it : m)
   {
      if (it.second % 2 == 0)
         count += it.second;
      else
         count += it.second - 1;
   }
   if (count < s.length())
      count++;
   return count;
}

int main()
{
   string s;
   cin >> s;
   cout << longestPalindrome(s) << endl;
}