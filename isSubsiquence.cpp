#include<bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t) {
        map<char, int>m1, m2;
        if(s.length()==0) return true;
        size_t found=-1;
        int count=0;
        for(int i=0;i<s.length();i++){
           found=t.find(s[i],found+1);
           if(found != string::npos) count+=1;
            else{
                return false;
            }
       }
       return true;
    }

    int main(){
      string s,t;
      cin>>s>>t;
      bool ans = isSubsequence(s,t);
      cout<<ans<<endl;
    }