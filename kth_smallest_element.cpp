#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{7, 10, 4, 3, 20, 15};
   int k = 3;
   priority_queue<int>maxHeap;
   for(int i=0;i<vec.size();i++){
      maxHeap.push(vec[i]);
      if(maxHeap.size()>k){
         maxHeap.pop();
      }
   }
   cout<<maxHeap.top()<<endl;
}