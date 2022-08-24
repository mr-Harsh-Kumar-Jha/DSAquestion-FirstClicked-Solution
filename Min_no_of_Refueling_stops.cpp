#include<bits/stdc++.h>
using namespace std;

int minStops(int target  , int startFuel , vector<vector<int>> & stations){
    priority_queue<int>pq;
   int distance = startFuel;
   int count =0 ,i=0;
   while(distance < target){
      while(i<stations.size() and distance>=stations[i][0]){
         pq.push(stations[i][1]);
         i++;
      }
      if(pq.empty()) return -1;
      distance+=pq.top();
      pq.pop();
      count++;
   }
   return count;
}

int main(){
      int target =100;
      int startFuel = 10;
      vector<vector<int>> vec;
      vector<int>vecpro;
      for(int i=0;i<3;i++){
         int a,b;
         cin>>a>>b;
          vecpro.push_back(a);
          vecpro.push_back(b);
          vec.push_back(vecpro);
      }
     cout<< minStops(target , startFuel ,vec);
}