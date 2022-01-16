#include<bits/stdc++.h>

using namespace std;

int add(int arr[],int size){
   int sum=0;
   for(int i=0;i<size;i++){
      sum=sum+arr[i];
   }
   return sum;
}

int recurse(vector<int>&sh,int arr[],int i,int sum1,int size){
   int sum2=0;
   for(;i<size;i++){
      sh.push_back(arr[i]);
      sum1=sum1+arr[i];
      arr[i]=0;
      sum2=add(arr,size);
      // base case
      if(sum1==sum2){
         return 1;
      }
      // Recursion
      if(recurse(sh,arr,i+1,sum1,size)==1){
         return 1;
      }
      // Back tracking
      sum2=0;
      arr[i]=sh.back();
      sh.pop_back();
      sum1=sum1-arr[i];
   }
   return 0;
}

int main(){
   int arr[]={2, 6, 7};
   vector<int>sh;
   int size=sizeof(arr)/sizeof(arr[0]);
   int i=0;
   int sum1=0;
   int temp=recurse(sh,arr,i,sum1,size);
   if(temp==1){
      cout<<"yes"<<endl;
   }
   else
     cout<<"not possible"<<endl;
}