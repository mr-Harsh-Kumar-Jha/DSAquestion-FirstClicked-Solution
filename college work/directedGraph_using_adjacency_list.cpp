#include<bits/stdc++.h>
using namespace std;

struct node{
   char city;
   node* nextConnected = NULL;
   node* individualCity = NULL;
};

void adjancencyList(char city, char connectedCity, node* graph){
   node* temp2 = graph;
   node* temp = new node();
   temp->city = connectedCity;
   while(temp2!=NULL && temp2->city!=city){
      temp2 = temp2->individualCity;
   }
   if(temp2->nextConnected!=NULL){
      temp2 = temp2->nextConnected;
   }
   temp2->nextConnected = temp;
}

int main(){
   int n;
   cout<<"Enter no of Airports ";
   cin>> n;
  node* graph = new node();
  graph = NULL;
  node* temp1 ;
   for(int i=0;i<n;i++){
      char city;
      cin>>city;
      node*temp = new node();
      temp->city=city;
      if(graph==NULL){
         graph = temp;
         temp1 = graph;
      }
      else{
         temp1->individualCity = temp;
         temp1 = temp1->individualCity;
      }
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
         adjancencyList(city,connectedCity,graph);
         break;

         case 2: cin>>fuelIntake;
         break;

         case 3: flag=1;
         break;

         default: cout<<"Enter correct choice "<<endl;
      }
   }
   node* temp2 = new node();
   node* temp3 = new node();
   temp3 = graph;
   temp2 = temp3->nextConnected;
   cout<<temp3->city<<" "<<temp3->nextConnected->city<<endl;
   while(temp3!=NULL){
      cout<<temp3->city;
      while(temp2!=NULL){
         cout<<"--->"<<temp2->city;
         temp2 = temp2->nextConnected;
      }
      cout<<"-->"<<temp2;
      cout<<endl;
      if(temp3!=NULL){
         temp3=temp3->individualCity;
         if(temp3!=NULL && temp3->nextConnected!=NULL) temp2 = temp3->nextConnected;
      }else temp2 = NULL;
   }
   cout<<endl;
}