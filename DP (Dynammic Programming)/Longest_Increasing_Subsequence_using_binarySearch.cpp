// this is a very god concept very binary search is been used . the concept behind it is that we will keep on adding digits in another array with respect to the condition and when the conditon fails we will replace it with the smallest digit present in the ans array , this array will not give us the exact  LIS but it will only give us the size of the LIS .

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{10,9,2,5,3,7,101,18};
   int n = vec.size();
   vector<int>ans;
   ans.push_back(vec[0]);
   for(int i=1;i<vec.size();i++){
      if(vec[i]>ans.back()){
         ans.push_back((vec[i]));
      }
      else{
         int ind = lower_bound(ans.begin(),ans.end(),vec[i])-ans.begin(); // binary search
         ans[ind] = vec[i];
      }
   }
   cout<<ans.size()<<endl;
}