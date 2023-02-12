// The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:

// It has a length of k.
// It is a divisor of num.
// Given integers num and k, return the k-beauty of num.

// Note:

// Leading zeros are allowed.
// 0 is not a divisor of any value.
// A substring is a contiguous sequence of characters in a string.

// Input: num = 240, k = 2
// Output: 2
// Explanation: The following are the substrings of num of length k:
// - "24" from "240": 24 is a divisor of 240.
// - "40" from "240": 40 is a divisor of 240.
// Therefore, the k-beauty is 2.

//=================================================================================

#include<bits/stdc++.h>
using namespace std;

int divisorSubstrings(int num, int k){
   ostringstream str1;
   str1 << num;
   string s = str1.str();
   int n = s.length();
   int i=0,j=0,count=0;
   while(j<n){
      if(j-i+1<k){
         j++;
      }
      else if(j-i+1==k){
         string newStr = s.substr(i , k);
         int intConv = stoi(newStr);
         if(intConv!=0 && num%intConv==0) count++;
         i++;
         j++;
      }
   }
   return count;
}

int main(){
   int num = 1342131;
   int k = 3;
   divisorSubstrings(num, k)?cout<<"true"<<endl:cout<<"false"<<endl;
}