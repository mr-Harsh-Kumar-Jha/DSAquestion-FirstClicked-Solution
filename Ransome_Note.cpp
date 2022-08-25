// https://leetcode.com/problems/ransom-note/

// fastest solution because of storing frequency of letters in the array of 26 as there are only 26 characters in the array , and the time required to iterate this array will also be less in comparison of travercing a string of length 10^5.
#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
   int freq1[26] = {-1};
   int freq2[26] = {-1};

   for (int i = 0; i < ransomNote.size(); i++)
      freq1[ransomNote[i] - 'a']++;
   for (int i = 0; i < magazine.size(); i++)
      freq2[magazine[i] - 'a']++;

   for (int i = 0; i < 26; i++)
   {
      if (freq1[i] > freq2[i])
         return false;
   }
   return true;
}

int main(){
   string a,b;
   cin>>a>>b;
   cout<<canConstruct(a,b);
}