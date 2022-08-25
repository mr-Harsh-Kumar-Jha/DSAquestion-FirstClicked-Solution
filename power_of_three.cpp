//This is one of the fastest solution as , Any integer number other than power of 3 which divides highest power of 3 value that integer can hold 3^19 = 1162261467

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
   if (n == 0)
      return false;
   int a = pow(3, (int)(log((1LL << 31) - 1) / log(3)));
   if (a % n == 0 && n > 0)
      return true;
   return false;
}

int main()
{
   int n;
   cin >> n;
   cout << isPowerOfThree(n);
}