#include<bits/stdc++.h>
using namespace std;

int main(){
   string s = "abaaaaccccaaadb";
   int  uniqueChar = 3;
   map<char ,int>ss;
   int i=0,j=0, max=-1;
   while(i<=s.length()){
      if(ss.size()<uniqueChar){
         ss[s[i]]++;
         i++;
      }
       if(ss.size()==uniqueChar){
           ss[s[i]]++;
           if(max<i-j){
            max = i-j;
           }
           i++;
       }
       if(ss.size()>uniqueChar){
           while(ss.size()>uniqueChar){
               if(ss[s[j]]==0) ss.erase(s[j]);
               else{
                  ss[s[j]]--;
                  if(ss[s[j]]==0) ss.erase(s[j]);
               }
               j++;
           }
       }
   }
   cout<<max<<endl;
}