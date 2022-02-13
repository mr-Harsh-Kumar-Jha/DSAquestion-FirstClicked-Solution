// Given an array A consisting of N integers A1,A2,…,AN, determine if you can sort this array by applying the following operation several times (possibly, zero):

// Pick a pair of indices (i,j) with i≠j and Ai&Aj≠0, and swap the values of Ai and Aj. Here, & denotes the bitwise AND operation.
// For example, if A=[6,4,2], the two possible operations are (1,2) and (1,3). (2,3) cannot be performed because A2&A3=4&2=0.

#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
   int temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int sorted(int arr[], int i, int j, int size)
{
   if (is_sorted(arr, arr + size))
   {
      return 1;
   }
   while (i < size)
   {
      if (arr[i] > arr[j] && ((arr[i] & arr[j]) != 0))
      {
         swap(arr, i, j);
         if (sorted(arr, i, i + 1, size) == 1)
         {
            return 1;
         }
         swap(arr, i, j);
         if (j < size)
            j = j + 1;
         else
         {
            i = i + 1;
            j = i + 1;
         }
         continue;
      }
      if (j < size)
         j = j + 1;
      else
      {
         i = i + 1;
         j = i + 1;
      }
   }
   return 0;
}

int main()
{
   int t;
   int *arr;
   int size;
   int temp;
   int i;
   int j;
   cin >> t;
   while (t--)
   {
      i = 0;
      j = 1;
      cin >> size;
      arr = new int[size];
      for (int k = 0; k < size; k++)
      {
         cin >> arr[k];
      }

      if (sorted(arr, 0, 1, size) == 1)
      {
         cout << "yes" << endl;
      }
      else
      {
         cout << "no" << endl;
      }
      delete (arr);
   }

   return 0;
}
