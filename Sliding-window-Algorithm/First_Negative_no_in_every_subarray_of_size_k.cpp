#include <bits/stdc++.h>
using namespace std;

int main()
{
   vector<int> vec{-1, 3, -8, 4, -5, 6};
   int n = vec.size();
   int k = 2;
   int start = 0, end = 0;
   list<int> list;
   vector<int> ans;
   while (end < n)
   {
      //this condition is checking whether the gap is set to k
      if (end-start<= k-1){
         if (vec[end] < 0) list.push_back(vec[end]);
         end++;
      }
      else{
         //now if the gap is set to k then check whether any negative element existed i.e list should not be empty .
         if (list.size()==0){
            if (vec[end] < 0) list.push_back(vec[end]);
            end++;
            start++;
         }
         else{
            // if the list is not empty then kindly check whether the prev start position element == the element in front of the list which acts as first -ve element .
            if (vec[start] == list.front()){
               int a = list.front();
               ans.push_back(a); // if exist we will push the element in the array and pop it out from the list .
               list.pop_front();
            }
            else{
               // if is not equal then push the element in the array
               int a = list.front();
               ans.push_back(a);
            }
            start++;
            if (vec[end] < 0){
               list.push_back(vec[end]);
               end++;
            }
         }
      }
   }
   // this is the case where the last subarry is considered and its first negative element is not taken into account so it is handled here .
   if(list.size()!=0){
      ans.push_back(list.front());
      list.pop_front();
   }
   // printing the ans array.
   for (int i = 0; i < ans.size(); i++)
   {
      cout << ans[i] << " ";
   }
   cout << endl;
}