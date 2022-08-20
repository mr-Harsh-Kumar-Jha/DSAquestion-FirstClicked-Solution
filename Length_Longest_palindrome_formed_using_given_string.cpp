#include<bits/stdc++.h>
using namespace std;

 int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }
        int ans = 0, ans1 = 0;
        for(auto it: freq) {
            if(it.second % 2 == 1)
                ans1 = 1;
            ans += it.second / 2;
        }
        return ans * 2 + ans1;
    }

    int main(){
      string s;
      cin>>s;
      cout<<longestPalindrome(s)<<endl;
    }