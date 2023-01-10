//this algorithm only work when the elements in verctor are in the range 0 to n . time complexity of the solution is O(n) and space complexity is O(1);

#include<bits/stdc++.h>
using namespace std;

void CycleSort(vector<int>&vec){
     int i=0;
     while(i<vec.size()){
      if(vec[i]<=vec.size() && vec[vec[i]-1]!=vec[i]) swap(vec[i] , vec[vec[i]-1]);
      else i++;
     }
}

int main(){
   vector<int>vec{2,1,5,4,3};
   CycleSort(vec);
   for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
   cout<<endl;
}