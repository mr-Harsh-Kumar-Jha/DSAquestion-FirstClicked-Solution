// here pivot is considered to be the last element i.e element which is present at the high position .

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partitation(vector<int>&vec , int low , int high ){
   int pivot = vec[high];
   int i = (low- 1);

    for (int j = low; j <= high - 1; j++) {

      if (vec[j] < pivot){
            i++;
            swap(vec[i], vec[j]);
      }
   }
   swap(vec[i + 1], vec[high]);
   return (i + 1);
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