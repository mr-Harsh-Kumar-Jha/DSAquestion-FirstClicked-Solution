time complexity O(size_0f_vector*size!)

#include <bits/stdc++.h>
using namespace std;

void combination(int arr[],int size,int i,int sum,int target, vector<int>&store){

//   cout<<sum<<endl;
   if(sum>target){
       return;
   }
   if(sum==target){
       for(auto temp:store){
           cout<<temp<<" ";
       }
       cout<<endl;
       return;
   }

   for(i;i<size;i++){
       sum=sum+arr[i];
       store.push_back(arr[i]);
       combination(arr,size,i,sum,target,store);
       store.pop_back();
       sum=sum-arr[i];
   }
   //  return ;
}

int main() {

  int arr[] = {6,5,7,1,8,2,9,9,7,7,9};
  int target=6;
  int size=sizeof(arr)/sizeof(arr[0]);
  vector<int>store;
  int sum=0;
  int i=0;
   sort(arr, arr + size);
  combination(arr,size,i,sum,target,store);
    return 0;
}