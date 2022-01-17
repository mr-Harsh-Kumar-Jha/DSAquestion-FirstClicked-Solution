//  time complexity is of O(n^3)

#include <bits/stdc++.h>
using namespace std;

void palindrome(string str, int i, int size,string result){
   // cout<<"hi="<<result<<endl;
    if(size==0){
      //  cout<<"b"<<endl;
        cout<<result<<endl;
        return;
    }
   //  cout<<"b"<<endl;
    for(;i<=size;i++){
        string sub=str.substr(0,i);
        string sub2=sub;
        string previous=result;
      //   cout<<"sub2="<<sub<<endl;
        reverse(sub2.begin(), sub2.end());
        if(sub.compare(sub2)==0){
         //   cout<<"b"<<endl;
            result=result+sub+" ";
            palindrome(str.substr(i,size-i),1,size-i,result);
        }
        result=previous;
    }
   //  return ;
}

int main() {
    string str="geeks";
    string result="";
    int i=1;
    int size=str.size();
    palindrome(str,i,size,result);

    return 0;
}