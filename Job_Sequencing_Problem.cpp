// this is the program to calculate max profit of the work provided....

#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<pair<int, int>> v;
   v.push_back({100, 2});
   v.push_back({19, 1});
   v.push_back({27, 3});
   v.push_back({25, 2});
   v.push_back({35, 3});
   int i = 0;
   sort(v.begin(), v.end());
   int prev[3] = {-1, -1, -1};
   vector<int> m;
   int count=3; // here 3 is no. max dedline of work appointed
   for (int i = 4; i >= 0; )
   {
      if(count<=0){
          break;
      }

      if (v[i].second-1 >=0 && prev[v[i].second-1] == -1)
      {
         m.push_back(v[i].first);
         count=count-1;
         prev[v[i].second-1]=find(v.begin(),v.end(),v[i])-v.begin() ;
         i=i-1;
      }
      else if(v[i].second-1>0){
         v[i].second=v[i].second-1;
      }
      else{
         i=i-1;
      }
   }
   int maxProfit=0;
   for(auto it:m){
      maxProfit=maxProfit+it;
   }

   cout<<maxProfit<<endl;

   //wrong approach i just created a vector and then i created a map and tried pushing max amount acc to deadling (i.e if we are given deadline of 1day for 3 projects then it will take max among them and if deadling is of 2-days for 4 projects then it will chose max among these 4 amount and so on..)

   // for(auto it:v){
   //     if(it.first == prev.first ){
   //        if(it.second >= prev.second){
   //           m[it.first]=it.second;
   //           prev=it;
   //        }
   //     }
   //     else if(it.first !=prev.first){
   //        m[it.first]=it.second;
   //        prev=it;
   //     }
   // }
   // int maxProfit=0;
   // for(auto it:m){
   //    maxProfit+=it.second;
   // }
   // cout<<maxProfit<<endl;

   return 0;
}