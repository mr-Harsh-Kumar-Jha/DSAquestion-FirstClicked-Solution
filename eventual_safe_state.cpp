#include<bits/stdc++.h>
using namespace std;

class Solution {

  private:
    bool dfs(int i, vector<int>&visited_node, vector<int>&visited_path, vector<int>adj[], int v, vector<int>&ans){
        visited_node[i]=1;
        visited_path[i]=1;

        for(auto it:adj[i]){
            if(!visited_node[it]){
                if(dfs(it,visited_node, visited_path, adj, v, ans)==true){
                    ans[i]=0;
                    return true;
                }
            }else if(visited_path[it]==1){
                ans[i]=0;
                return true;
            }
        }
        ans[i]=1;
        visited_path[i]=0;
        return false;
    }

  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>visited_node(V,0), visited_path(V,0);
        vector<int>ans(V,0), safeNode;

        for(int i=0;i<V;i++){
            if(!visited_node[i]){
                dfs(i, visited_node, visited_path, adj, V, ans);
            }
        }

        for(int i=0;i<V;i++){
            if(ans[i]==1) safeNode.push_back(i);
        }
        return safeNode;
    }
};