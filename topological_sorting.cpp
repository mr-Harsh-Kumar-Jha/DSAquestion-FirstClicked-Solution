#include<bits/stdc++.h>
using namespace std;

class Solution
{

    private:
    void dfs(int node, vector<int>&vist, stack<int>&stack, vector<int> adj[], int v){
        vist[node]=1;
        for(auto it:adj[node]){
            if(vist[it]==0){
                dfs(it, vist, stack, adj, v);
            }
        }
        stack.push(node);
    }

	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    vector<int>vist(V,0);
	    stack<int>stack;
	    for(int i=0;i<V;i++){
	        if(!vist[i])
	            dfs(i, vist, stack, adj, V);
	    }
	    int i=0;
	    while(!stack.empty()){
	        int ans = stack.top();
	        stack.pop();
	        vist[i]=ans;
	        i++;
	    }
	    return vist;
	}
};