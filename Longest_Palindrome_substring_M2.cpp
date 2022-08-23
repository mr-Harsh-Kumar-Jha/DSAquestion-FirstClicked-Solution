//This is a brute force approach where i have solved this question in O(n^3) and space complexity of O(n);

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
   int max = 0;
   string ans;
   for (int i = 0; i < s.length(); i++)
   {
      string subStr;

      for (int j = i; j < s.length(); j++)
      {
         subStr += s[j];
         string rev_subst = subStr;
         reverse(rev_subst.begin(), rev_subst.end());
         if (subStr.length() > max && subStr == rev_subst)
         {
            max = subStr.length();
            ans = subStr;
         }
         // cout << subStr << endl;
      }
   }
   return ans;
}

int main(){
   string s;
   cin>>s;
   cout<<longestPalindrome(s)<<endl;
}