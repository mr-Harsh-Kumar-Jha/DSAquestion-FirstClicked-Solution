// here condition value also have to given by us as condition is given that find max substring with every character to be unique

#include<bits/stdc++.h>
using namespace std;

int main(){
   string s = "abaaaaccccameadb";
   map<char,int> m ;
   int i=0,j=0,maxs=INT_MIN;
   int size = s.length();
   while(j<size){
      m[s[j]]++;
      j++;
      if(m.size()==j-i){
         int s = m.size();
        maxs = max(maxs,s);
      }
      else if(m.size()<j-i){
         while(m.size()<j-i){
             if(m[s[i]]==0) m.erase(s[i]);
           else{
               m[s[i]]--;
               if(m[s[i]]==0) m.erase(s[i]);
               i++;
           }
         }
      }
   }
   // for(auto it:m){
   //    cout<<it.first<<it.second<<" ";
   // }
   cout<<maxs<<endl;
}