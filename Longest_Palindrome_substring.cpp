//https://leetcode.com/problems/longest-palindromic-substring/

// this is one of the most optimised solution where time Complexity = O(n^2) and space complexity = O(1). This is optimised over DP . This is basically based on the concept that palindrome mirrors around center .

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
   int i = 0, j = 0, n = s.size(), lmax = 0;
   string p;
   while (i < n)
   {
      int i1 = i, j1 = j;
      while (j1 >= 0 && i1 < n)
      {
         if (s[i1++] != s[j1--])
            break;
         int l = i1 - j1 - 1;
         if (l > lmax)
         {
            lmax = l;
            p = s.substr(j1 + 1, l);
         }
      }
      if (i == j)
         i++;
      else
         j++;
   }
   return p;
}

int main()
{
   string s;
   cin>>s;
   cout<<longestPalindrome(s);
}
