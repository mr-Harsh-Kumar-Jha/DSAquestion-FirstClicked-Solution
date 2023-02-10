// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
   map<char, int> tChar;
   int count = 0;
   for (int i = 0; i < t.length(); i++){
      tChar[t[i]]++;
      count++;
   }
   int i = 0, j = 0, min = INT_MAX;
   string ansStr = "";
   while (j < s.length()){
      if (count > 0 && tChar.find(s[j]) != tChar.end()){
         tChar[s[j]]--;
         if (tChar[s[j]] >= 0)
            count--;
         j++;
      }
      else
         j++;
      if (count == 0){
         if (min > j - i){
            min = j - i;
            ansStr = s.substr(i, (j - i));
         }
         while (count == 0){
            if (tChar.find(s[i]) != tChar.end()){
               tChar[s[i]]++;
               if (tChar[s[i]] > 0){
                  if (min > j - i) {
                     min = j - i;
                     ansStr = s.substr(i, (j - i));
                  }
                  count++;
               }
            }
            i++;
         }
      }
   }
   return ansStr;
}

int main(){
   string str1 = "ADOBECODEBANC";
   string str2 = "ABC";
   cout<<minWindow( str1, str2)<<endl;
}