#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
   stack<char> st;
   for (auto i : s){
      if (i == '(' or i == '{' or i == '[')
         st.push(i);
      else{
         if (st.empty() or (st.top() == '(' and i != ')') or (st.top() == '{' and i != '}') or (st.top() == '[' and i != ']'))
            return false;
         st.pop();
      }
   }
   return st.empty();
}

int main(){
   string s;
   cin>>s;
   cout<<isValid(s)<<endl;
}