#include<bits/stdc++.h>
using namespace std;

int burstBalloons(vector<int>&vec,int i,int j){
   if(i>j) return 0;
   int mini = INT_MIN;
   for(int ind = i;ind<=j;ind++){
      int cost = (vec[i-1]*vec[ind]*vec[j+1]) + burstBalloons(vec,i,ind-1) + burstBalloons(vec, ind+1,j);
      mini = max(mini,cost);
   }
   return mini;
}

int main(){
   vector<int>vec{1,5};
   int n = vec.size();
   vec.insert(vec.begin(), 1);
   vec.push_back(1);
   cout<<burstBalloons(vec,1,n)<<endl;
}