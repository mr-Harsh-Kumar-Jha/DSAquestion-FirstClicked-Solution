#include<bits/stdc++.h>
#define v 5
using namespace std ;

void printMST(int parent[v], int graph[v][v]){
   for(int i=1;i<v;i++){
      cout<<parent[i]<<" - "<<i<<" \t "<<graph[i][parent[i]]<<endl;
   }
}
int selectMinVertex(vector<int> & value , vector<bool> & setMST){
   int min = INT_MAX;
   int vertex ;
   for(int i=0;i<v;i++){
      if(value[i]<min && !setMST[i]){
         min=value[i];
         vertex=i;
      }
   }
   return vertex;
}

void findMST( int  graph[v][v]){
       int parent[v];
       vector<int> value(v , INT_MAX);
       vector<bool> setMST(v , false);
       parent[0]=-1;
       value[0]=0;
       for(int i=0;i<v-1;i++){
          int u=selectMinVertex(value, setMST);
          setMST[u]=true;
          for(int j=0 ; j<v ; j++){
               if(graph[u][j]!=0 && setMST[j]==false && value[j]>graph[u][j]){
                  value[j]=graph[u][j];
                  parent[j]=u;
               }
          }
       }
       printMST(parent, graph);
}

int main (){
   int graph[v][v] = { { 0, 2, 0, 6, 0 },
                                   { 2, 0, 3, 8, 5 },
                                   { 0, 3, 0, 0, 7 },
                                   { 6, 8, 0, 0, 9 },
                                   { 0, 5, 7, 9, 0 } };

   findMST(graph);
}
