#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>&m1 , pair<int,int>&m2){
    return m1.second < m2.second;
}

int main(){
   vector<int>vec{1,1,2,1,3,2,4,3,3,3,1};
   vector<pair<int,int>>ans;
   map<int,int>m;
   for(int i=0;i<vec.size();i++){
        m[vec[i]]++;
   }
   for(auto it : m){
      ans.push_back({it.first,it.second});
   }
   sort(ans.begin(),ans.end(),compare);
   for(auto it:ans){
      while(it.second!=0){
         cout<<it.first<<" ";
         it.second--;
      }
   }
   cout<<endl;
   return 0;
}
