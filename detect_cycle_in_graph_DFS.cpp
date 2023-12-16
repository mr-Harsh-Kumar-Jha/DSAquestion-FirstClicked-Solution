#include<bits/stdc++.h>
using namespace std;

class Solution {

  private:
    bool dfs(int i, vector<int>&visited_node, vector<int>&visited_path, vector<int>adj[], int v){
        visited_node[i]=1;
        visited_path[i]=1;
        if(adj[i].size()==0){
           visited_path[i]=0;
           return false;
        }
        for(auto it:adj[i]){
            if(visited_node[it]==0){
                if(dfs(it,visited_node, visited_path, adj, v)==true){
                    return true;
                }
            }else if(visited_node[it]==1 && visited_path[it]==1) return true;
        }
        visited_path[i]=0;
        return false;
    }

  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>visited_node(V,0);
        vector<int>visited_path(V,0);
        for(int i=0;i<V;i++){
            if(!visited_node[i])
                if(dfs(i, visited_node, visited_path, adj, V)==true) return true;
        }
        return false;
    }
};