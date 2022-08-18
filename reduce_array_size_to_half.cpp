#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int> &arr)
{
   unordered_map<int, int> m;
   multimap<int, int> vec;
   sort(arr.begin(), arr.end());
   for (int i = 0; i < arr.size(); i++)
   {
      m[arr[i]]++;
   }
   for (auto it : m)
   {
      vec.insert(pair<int, int>(it.second, it.first));
   }
   int size = arr.size();
   int ans = size;
   int count = 0;
   for (auto it = vec.rbegin(); it != vec.rend(); it++)
   {
      if (ans <= (size / 2))
      {
         return count;
      }
      ans -= it->first;
      count += 1;
   }
   return count;
}

int main(){
   vector<int> input;
   int size ;
   cin>>size;
   for(size_t i=0;i<size;i++){
      int a;
      cin>>a;
      input.push_back(a);
   }
   cout<< minSetSize(input);
}