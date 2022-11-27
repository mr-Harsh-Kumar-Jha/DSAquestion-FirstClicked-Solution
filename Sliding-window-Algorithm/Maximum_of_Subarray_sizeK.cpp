//logic behind this solution is that max element se pahle wale sare elements are useless and the elements after max elements are useful as there is huge chance that latter in further subarray among these elements anyone can act as max element

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{1,3,2,-5,-1,4,5,3};
   int n = vec.size();
   int start = 0 , end=0;
   list<int>lst;
   vector<int>ans;
   int k = 3;
   while(end<n){
      if(!lst.empty()){
         while(!lst.empty() && lst.back()<vec[end]){
            lst.pop_back();
         }
         lst.push_back(vec[end]);
      }
      else lst.push_back(vec[end]);
      if(end-start+1<k) end++;
      else{
          if(lst.front()==vec[start]){
            ans.push_back(lst.front());
            lst.pop_front();
          }
          else{
            ans.push_back(lst.front());
          }
          start++;
          end++;
      }
   }
   for(auto it:ans){
      cout<<it<<" ";
   }

}