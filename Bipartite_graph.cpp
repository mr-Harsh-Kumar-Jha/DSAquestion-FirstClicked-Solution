#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool bfs(int i, int ans[], vector<int>adj[], int v){
        queue<int>q;
        q.push(i);
        ans[i]=0;
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(auto it: adj[vertex]){
                if(ans[it]==-1){
                   ans[it] = !ans[vertex];
                   q.push(it);
                }else if(ans[it]==ans[vertex]) return false;
            }
        }
        return true;
    }

	bool isBipartite(int v, vector<int>adj[]){
	    int ans[v];
	    for(int i=0;i<v;i++) ans[i]=-1;
	    for(int i=0;i<v;i++){
	        if(ans[i]==-1){
	            if(bfs(i,ans,adj, v)==false) return false;
	        }
	    }
	    return true;
	}

};