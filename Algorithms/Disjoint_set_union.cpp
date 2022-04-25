#include<bits/stdc++.h>
using namespace std;
vector<int> dsu;

int find(int v){
   if(dsu[v]==-1)
      return v;

   return find(dsu[v]);
}

void union_op(int from, int to){
   from=find(from);
   to=find(to);

   dsu[from]=to;
}

int isCyclic(vector<pair<int,int>>& edge_list){
   for(auto & it:edge_list){
      int fromp=find(it.first); // find absolute parent of subset
      int top=find(it.second);

      if(fromp==top){
         return 1;
      }

      union_op(fromp , top); //union of two sets.
   }
   return 0;
}

int main(){
   int E,v; // no of edges , no of vertices
   cin>>E>>v;
   dsu.resize(v, -1); //mark all vertices as seperate subset with only one element
   vector<pair<int, int>>edge_list;

   for(int i=0;i<E;i++){
      int from ,to;
      cin>>from>>to;
      edge_list.push_back({from, to});
   }

   if(isCyclic(edge_list)){
      cout<<"true"<<endl;
   }
   else{
      cout<<"false"<<endl;
   }
   return 0;

}