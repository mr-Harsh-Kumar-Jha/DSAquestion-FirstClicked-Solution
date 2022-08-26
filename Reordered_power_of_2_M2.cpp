//https://leetcode.com/problems/reordered-power-of-2/

// here i am just trying to sort the given no and the generated power of two by converting it to string , comparing these two strings .

#include <bits/stdc++.h>
using namespace std;

bool reorderedPowerOf2(int n)
{
   // store number as string to sort the digits
   string num = to_string(n);

   sort(num.begin(), num.end());

   for (int i = 0; i <= 30; i++)
   {
      string s = to_string(1 << i);
      sort(s.begin(), s.end());
      if (s == num)
         return true;
   }
   return false;
}

int main()
{
   int n;
   cin >> n;
   cout << reorderedPowerOf2(n) << endl;
}