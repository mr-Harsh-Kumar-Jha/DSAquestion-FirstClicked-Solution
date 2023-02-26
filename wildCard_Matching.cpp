//this is just a rucursive approach the optimised solution to this solution is done using dp .

// the logic is very simple as u can see we are said that if '?' occurs then it can replace any one character , whereas when '*' occurs then it can replace sequence of character and so when there is '*' present then we are considering 2 cases like either we can keep it un matched or we can match it one by one with all characters  , and we will take 'or' because by considering any sequence we can get our ans so if any one will be true we will can match this sequence .

#include<bits/stdc++.h>
using namespace std;

bool wildcardMatch(string &s1 , string &s2 , int n , int m){
   if(n>=0 && m<0) return false;
   if(n<0 && m<0) return true;
   if(m>=0 && n<0){
      for(int i=0;i<=m;i++){
         if(s2[i]!='*') return false;
      }
      return true;
   }

   if(s1[n]==s2[m] || s2[m]=='?') return wildcardMatch(s1,s2,n-1,m-1);
   if(s2[m]=='*'){
      return (wildcardMatch(s1,s2,n,m-1)  | wildcardMatch(s1,s2,n-1,m));
   }
   return  false;
}

int main(){
   string s1  = "cb";
   string s2 = "?b";
   int n = s1.length();
   int m = s2.length();
   if(wildcardMatch(s1,s2,n-1,m-1)==0) cout<<"false"<<endl;
   else cout<<"true"<<endl;
}