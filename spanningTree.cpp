// Time Complexity : O(Elog(V));
// Space Complexity : O(V^2);

#include<bits/stdc++.h>
#include "libraries/Priority_Queue.h"
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){
   vector<int> visited(V, 0);

   // wt, node
   Priority_Queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   pq.push({0, 0});
   int sum = 0;
   while (!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int node = it.second;
      int wt = it.first;
      if (visited[node] == 1)
         continue;

      visited[node] = 1;
      sum += wt;
      for (auto it : adj[node]){
         int adjNode = it[0];
         int edjWeight = it[1];

         if (!visited[adjNode]){
            pq.push({edjWeight, adjNode});
         }
      }
   }
   return sum;
}

int main(){
   int V,E;
   cin>>V>>E;
   vector<vector<int>> vec[V];
   while(E--){
      int u,v,w;
      cin>>u>>v>>w;
      vector<int>t1,t2;
      t1.push_back(v);
      t1.push_back(w);

      vec[u].push_back(t1);

      t2.push_back(u);
      t2.push_back(w);

      vec[v].push_back(t2);

   }
   cout<<spanningTree(V,vec)<<endl;
}