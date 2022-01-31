#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[]={5, 2, 3, 9, 4, 6, 7, 15, 32};
   int size=sizeof(arr)/sizeof(arr[0]);
   int count=0;
   map<int,vector<int>> bit;
   for(int i=0;i<size;i++){
      count=0;
      for(int j=31;j>=0;j--){
         if(((arr[i])&(1<<j))!=0){
            count+=1;
         }
      }
      bit[count].push_back(arr[i]);
   }

   map<int,vector<int>> ::reverse_iterator hi;
   for(hi = bit.rbegin();hi != bit.rend();hi++){
      //  cout<<hi->first<<endl;
       auto bro=hi->second;
       for(auto it: bro){
           cout<<it<<" ";
       }
   }

}