// this is the approach which is solved using topological sort
//approach:- so as there is need of printing all those nodes which ends at terminal node . so according to topological sort 1.] we first calculate indegree of each node and then we find those nodes whose indegree is zero .
//  2.]  sp for doing this we need to reverse the order of each node and then calculate  the inorder 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<int> eventualSafeNodes(int V, vector<int> adj[])
   {
      vector<int> adjRev[V], topoSort(V, 0), ans;

      queue<int> q;
      for (int i = 0; i < V; i++)
      {
         for (auto it : adj[i])
         {
            adjRev[it].push_back(i);
            topoSort[i]++;
         }
      }

      for (int i = 0; i < V; i++)
      {
         if (topoSort[i] == 0)
         {
            q.push(i);
         }
      }

      while (!q.empty())
      {
         int index = q.front();
         q.pop();
         ans.push_back(index);
         for (auto it : adjRev[index])
         {
            topoSort[it]--;

            if (!topoSort[it])
            {
               q.push(it);
            }
         }
      }
      sort(ans.begin(), ans.end());
      return ans;
   }
};