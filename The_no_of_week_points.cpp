// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include <bits/stdc++.h>
using namespace std;

static bool col(vector<int> &a, vector<int> &b)
{
   if (a[0] != b[0])
      return a[0] > b[0];
   return a[1] < b[1];
}
int numberOfWeakCharacters(vector<vector<int>> &properties)
{
   int maxi = INT_MIN;
   int cnt = 0;
   sort(properties.begin(), properties.end(), col);
   for (int i = 0; i < properties.size(); i++)
   {
      if (properties[i][1] < maxi)
      {
         cnt++;
      }
      else
      {
         maxi = properties[i][1];
      }
   }
   return cnt;
}

int main(){
   vector<vector<int>> vec{
      {1,7},
      {5,3},
      {4 , 5}
   };
   cout<<numberOfWeakCharacters(vec)<<endl;
}