// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

//-----------------------------------------------------------------------------------

// This is a space optimization solution where time complexity is same as m2 i.e     O(n*3*4) and space complexity  is O(2*4) which is almost equal to constant;

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<vector<int>> vec{
      {1, 100, 3},
       {9, 10, 8},
       {12, 11, 13},
   };
   vector<int>prev(4,0);
   prev[0] = max(vec[0][1], vec[0][2]);
   prev[1] = max(vec[0][0], vec[0][2]);
   prev[2] = max(vec[0][0], vec[0][1]);
   prev[3] = max(vec[0][0], max(vec[0][1], vec[0][2]));

   for(int day=1;day<vec.size();day++){
      vector<int>curr(4,0);
      for(int last = 0;last<4;last++){
         curr[last]=0;
         for(int task = 0;task<3;task++){
             int ans = vec[day][task]+prev[task];
             curr[last]=max(curr[last],ans);
         }
      }
      prev=curr;
   }
   cout<<prev[3]<<endl;
}