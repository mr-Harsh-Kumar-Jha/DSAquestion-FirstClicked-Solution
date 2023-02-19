// this is a O(n*length) time complexity solution and space complexity is O(length) here only one extra space is used 

#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int> price{2, 5, 7, 8, 10};
   int n = price.size();
   int length = 10;
   vector<int> prev(length + 1, 0);
   for (int i = 0; i <= length; i++){
      prev[i] = i * price[0];
   }
   for (int i = 1; i < n; i++){
      for (int j = 0; j <= length; j++){
         int take = INT_MIN;
         if (j >= i + 1) take = price[i] + prev[j - (i + 1)];
         int noTake = 0 + prev[j];
         prev[j] = max(take, noTake);
      }
   }
   cout << prev[length] << endl;
}