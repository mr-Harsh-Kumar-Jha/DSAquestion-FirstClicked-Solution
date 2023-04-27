#include<bits/stdc++.h>
using namespace std;

void adjancencyMatrix(char city, char connectedCity, vector<vector<int>>&graph, map<char,int>&map){
   int firstCity = -1 ,secondCity = -1;
   for(auto it:map){
      if(city==it.first){
         firstCity = it.second;
      }
      if(connectedCity==it.first){
         secondCity = it.second;
      }

      if(firstCity!=-1 && secondCity!=-1){
         graph[firstCity][secondCity] = 1;
         break;
      }
   }

}

int main(){
   int n;
   cout<<"Enter no of Airports ";
   cin>> n;
   vector<vector<int>>graph(n,vector<int>(n,0));
   map<char,int>map;
   for(int i=0;i<n;i++){
      char city;
      cin>>city;
      map[city] = i;
   }
   char city, connectedCity;
   int fuelIntake;
   int flag = 0;
   while(true){
      if(flag) break;
      cout<<"1.] input edges"<<endl;
      cout<<"2.] input fuel intake"<<endl;
      cout<<"3.] exit"<<endl;
      int option;
      cin>>option;
      switch(option){
         case 1: cin>>city;
         cout<<"enter connected city ";
         cin>>connectedCity;
         adjancencyMatrix(city,connectedCity,graph,map);
         break;

         case 2: cin>>fuelIntake;
         break;

         case 3: flag=1;
         break;

         default: cout<<"Enter correct choice "<<endl;
      }
   }

   for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
         cout<<graph[i][j]<<" ";
      }
      cout<<endl;
   }

}