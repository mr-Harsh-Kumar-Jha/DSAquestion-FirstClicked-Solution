#include <bits/stdc++.h>
using namespace std;

class Graph{

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
   void BFS(int s);
};

Graph::Graph(int V){
   this->V = V;
   adj.resize(V);
}

void Graph::addEdge(int v, int w){
   // Add w to v’s list.
   adj[v].push_back(w);
}

void Graph::BFS(int s){
   vector<bool> visited(V, false);
   queue<int> qt;

   visited[s] = true;
   qt.push(s);

   while (!qt.empty()){
      s = qt.front();
      cout << s << " ";
      qt.pop();

      // Get all adjacent vertices of the dequeued
      // vertex s.
      // If an adjacent has not been visited,
      // then mark it visited and enqueue it
      for (auto adjacent : adj[s]){
         if (!visited[adjacent]){
            visited[adjacent] = true;
            qt.push(adjacent);
         }
      }
   }
}

int main()
{
   // Create a graph given in the above diagram
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);

   cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
   g.BFS(2);

   return 0;
}