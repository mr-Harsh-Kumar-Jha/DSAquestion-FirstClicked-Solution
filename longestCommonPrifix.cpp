#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
         string string0 = strs[0];
         int count = 0;
         for(int i=1;i<strs.size();i++){
            string string1 = strs[i];
            count = 0;
            for(int j=0;j<min(string1.length(),string0.length());j++){
            if(string1[j]==string0[j]){
               count++;
            }
            else{
               break;
            }
         }
         if(count > 0){
               string0 = string1.substr(0,count);
         }
         else{
               string0 = "";
               break;
         }
      }
      return string0;
}

int main(){
    vector<string>vec{"buddy" , "buoy","bull"};
    cout<< longestCommonPrefix(vec)<<endl ;
}