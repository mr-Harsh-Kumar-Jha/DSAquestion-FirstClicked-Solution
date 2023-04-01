#include<bits/stdc++.h>
using namespace std;

void swap(int *a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> &arr,int n){
    for(int i=0;i<n-1;i++){
      int temp = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[temp]){
               temp = j;
            }
        }
        if(temp!=i){
            swap(&arr[i],&arr[temp]);
        }
    }
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
  vector<int>vec{2,1,4,3};
  int n = vec.size();
  selectionSort(vec,n);
}
