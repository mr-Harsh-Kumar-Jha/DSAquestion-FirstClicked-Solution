#include<bits/stdc++.h>
using namespace std;

void solve(int inc){
    int n,qq;
    cin>>n>>qq;
    vector<vector< int > >adj(n+1);
    int j=1,v,u;
    while(j<=n){
        cin>>v>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
        j++;
    }
    vector<int>hi(qq);
    for(int i=0;i<qq;i++) cin>>hi[i];

    vector<int>par(n+1,-1);
    queue<int>q;
    q.push(1);
    int ans =1;
    while(!q.empty()){
        int sz = q.size();
        qq-=sz;
        if(qq>=0){
            ans+=sz;
            for(int i=0;i<sz;i++){
                int u=q.front();
                q.pop();
                for(auto vec:adj[u]){
                    if(vec!=par[u]){
                        q.push(vec);
                        par[vec] = u;
                    }
                }
            }
            continue;
        }
        break;
    }
    cout<<"Case #"<<inc<<": "<<ans-1<<endl;

}
int main(){
    int t,j=1;
    cin>>t;
    while(t--){
        solve(j);
        j++;
    }
}