//https://leetcode.com/problems/reduce-array-size-to-the-half
// it is an well optimised solution as we used count sort 2 times

#include <bits/stdc++.h>
using namespace std;

inline static int counts[100001];
int minSetSize(vector<int> &arr)
{
   memset(counts, 0, sizeof(counts));

   for (const int &i : arr)
      ++counts[i];

   int freqs[size(arr) + 1];
   memset(freqs, 0, sizeof(freqs));

   for (int i = 1; i <= 100000; i++)
      if (counts[i])
         ++freqs[counts[i]];

   int n = (size(arr) + 1) / 2;
   int res = 0;

   for (int i = size(arr); n > 0; i--)
      while (freqs[i]-- and n > 0)
         n -= i, res++;

   return res;
}

int main()
{
   vector<int> input;
   int size;
   cin >> size;
   for (size_t i = 0; i < size; i++)
   {
      int a;
      cin >> a;
      input.push_back(a);
   }
   cout << minSetSize(input);
}