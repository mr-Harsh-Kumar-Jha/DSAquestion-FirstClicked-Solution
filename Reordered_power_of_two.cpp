//https://leetcode.com/problems/reordered-power-of-2/
// this is one of the fastest solution .
//NOTE :- there are only 10 unique digits 0-9 and for each number we can keep a count of digits from 0 to 9 and as 10^9 is approximately equal to 15*(2^26) we can also run a loop from 0 to 27 and find occurance of each digit of n and digit formed by taking power .

#include <bits/stdc++.h>
using namespace std;

int *count(int n)
{
   int *ans = new int[10];
   while (n > 0)
      ans[n % 10]++, n /= 10;
   return ans;
}
bool isEqual(int *arr1, int *arr2)
{
   for (int i = 0; i < 10; i++)
      if (arr1[i] != arr2[i])
         return false;
   return true;
}
bool reorderedPowerOf2(int &n)
{
   int *arr = count(n);
   for (int i = 0; i < 27; i++)
      if (isEqual(arr, count(1LL << i)))
         return true;
   return false;
}

int main()
{
   int n;
   cin >> n;
   cout << reorderedPowerOf2(n) << endl;
}