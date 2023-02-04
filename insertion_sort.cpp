#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&vec , int n){
   int i=0;
    while(i<n){
      int j=i-1;
      int temp = vec[i];
      while(j>=0){
          if(vec[j]>temp){
            vec[j+1]=vec[j];
            j--;
          }
          else{
            break;
          }
      }
      vec[j+1] = temp;
      i++;
    }
}

int main(){
   vector<int>vec{4,3,2,10,12,1,5,6};
   int n = vec.size();

   insertionSort(vec,n);
   for(int i=0;i<n;i++){
      cout<<vec[i]<<" ";
   }
   cout<<endl;
}