//https://leetcode.com/problems/pascals-triangle-ii/

#include <bits/stdc++.h>
using namespace std;
// this is a solution where i have used combination formula to solve the question

int calFact(int prev, int rowIndex, int colIndex)
{
   int ans = (((long long int)prev * rowIndex) - ((long long int)prev * colIndex) + ((long long int)prev * 1)) / colIndex;
   return ans;
}
vector<int> getRow(int rowIndex)
{
   vector<int> ans(rowIndex + 1);
   ans[0] = 1;
   for (int i = 1; i < rowIndex + 1; i++)
   {
      ans[i] = calFact(ans[i - 1], rowIndex, i);
   }
   return ans;
}

int main()
{
   int n;
   cin >> n;
}