// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void recurse(string str,multiset<string>s,string result,int n){
    if(result.size()==n){
            cout<<result<<"  ";
            return;
        }
    for(int i=0;i<n;i++){
        auto it=s.find(str.at(i));
        if(it){
            result=result+str.at(i);
            s.erase(s.find(str.at(i)));
            recurse(str,s,result,n);
            s.insert(str.at(i));
        }

    }
}

int main() {
    // Write C++ code here
   string str={"ABC"};
   int n=str.size();
   multiset<string>s;
   string result="";
   for(int i=0;i<n;i++){
       s.insert(str.at(i));
   }

   recurse(str,s,result,n);



    return 0;
}