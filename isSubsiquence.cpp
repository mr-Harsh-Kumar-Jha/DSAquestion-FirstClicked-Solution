// https://leetcode.com/problems/is-subsequence/
// one of the fastes code and well optimised

#include<bits/stdc++.h>

using namespace std;
// using find STL in string
    bool isSubsequence(string s, string t) {
        if(s.length()==0) return true;
        size_t found=-1;
        for(size_t i=0;i<s.length();i++){
           found=t.find(s[i],found+1);
           if(found == string::npos) return false;
       }
       return true;
    }

    int main(){
      string s,t;
      cin>>s>>t;
      bool ans = isSubsequence(s,t);
      cout<<ans<<endl;
    }