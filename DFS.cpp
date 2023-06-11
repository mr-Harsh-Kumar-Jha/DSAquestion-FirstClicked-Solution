#include <bits/stdc++.h>
using namespace std;

class Graph
{

   // No. of vertices
   int V;

   // Pointer to an array containing adjacency lists
   vector<list<int>> adj;

public:
   // Constructor
   Graph(int V);

   // Function to add an edge to graph
   void addEdge(int v, int w);

   // Prints BFS traversal from a given source s
   void DFS(int s);
};

Graph::Graph(int V)
{
   this->V = V;
   adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
   // Add w to v’s list.
   adj[v].push_back(w);
}

void Graph::DFS(int s){
   vector<bool> visited(V, false);
   stack<int> qt;

   visited[s] = true;
   cout << s << endl;
   qt.push(s);

   while (!qt.empty()){
      s = qt.top();
      // Get all adjacent vertices of the dequeued
      // vertex s.
      // If an adjacent has not been visited,
      // then mark it visited and enqueue it
      int count1 = adj[s].size();
      // cout<<adj[s].back()<<endl;
      int count2 = 0;
      for (auto adjacent : adj[s]){
         count2++;
         if (!visited[adjacent]){
            visited[adjacent] = true;
            qt.push(adjacent);
            cout << adjacent << endl;
            break;
         }
         if (count2 == count1){
            qt.pop();
         }
      }
      if (adj[s].back() == 0){
            qt.pop();
      }
   }
}

int main()
{
   // Create a graph given in the above diagram
   Graph g(8);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(0, 3);
   g.addEdge(1, 3);
   g.addEdge(2, 4);
   g.addEdge(3, 5);
   g.addEdge(3, 6);
   g.addEdge(4, 7);
   g.addEdge(4, 5);
   g.addEdge(5, 2);

   cout << "Following is Breadth First Traversal "
        << " \n";
   g.DFS(0);

   return 0;
}

// 0-1-2
// 1-2
// 2-0-3
// 3-3