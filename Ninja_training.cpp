//Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

//You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

//-----------------------------------------------------------------------------------

//This is a recrursive approach where no dp is used here time complexity is exponential and space complexity is O(n)+auxilliary space.

#include<bits/stdc++.h>
using namespace std;
int maxs=INT_MIN;
int solveNinja(vector<vector<int>>&vec , int ind , int utzInd  , int ans){
      if(ind < 0 ){
         if(maxs < ans){
            maxs=ans;
         }
         return 0;
      }
      for(int i=0;i<3;i++){
         if(i!=utzInd){
            ans+=vec[ind][i];
            solveNinja(vec,ind-1,i,ans);
            ans-=vec[ind][i];
         }
      }
      return maxs;
}

int main(){
   vector<vector<int>>vec{
      {90 ,45 ,5},
      {3 ,1 ,10},
      {3 ,100 ,3},
      {80,90,101},
      {34,55,70}
   };
  cout<<solveNinja(vec,vec.size()-1,-1,0)<<endl;
}