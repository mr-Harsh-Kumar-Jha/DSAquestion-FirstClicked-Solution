// Here the pivot element is the first positioned element

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partitation(vector<int>&vec , int low , int high){
   int pivot = vec[low];
   int i=low;
   int j=high;
   while(i<j){
      while(i<=vec.size()-1 && vec[i]<=pivot) i++;
      while(j>=0 && vec[j]>pivot) j--;
      if(i<j) swap(&vec[i],&vec[j]);
   }
   swap(&vec[j] , &vec[low]);
   return j;
}

void quickSort(vector<int>&vec ,int low,int high ){
   if(low < high){
      int par = partitation(vec,low,high) ;
      quickSort(vec, low, par - 1);
      quickSort(vec, par + 1, high);
   }
}

int main(){
   vector<int>vec{2,1,4,3};
   quickSort(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
      cout<<vec[i]<<" ";
    }
}