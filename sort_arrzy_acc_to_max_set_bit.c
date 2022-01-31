// time complexity O(n^2) and space complexity O(n)

#include <stdio.h>
#include <limits.h>

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6};
   int size = sizeof(arr) / sizeof(arr[0]);
   int count = 0;
   int max2 = 0;
   int max = INT_MIN;
   //   printf("%d",(arr[1])&(1<<1));
   int arr2[size];
   for (int i = 0; i < size; i++)
   {
      max = 0;
      for (int j = 0; j < size; j++)
      {
         count = 0;
         for (int k = 31; k >= 0; k--)
         {
            if (((arr[j]) & (1 << k)) != 0)
            {
               count += 1;
            }
         }
         if (count > max)
         {
            max = count;
            max2 = j;
         }
         // printf("%d\n", count);
      }
      // printf("%d\n", max2);
      arr2[i] = arr[max2];
      arr[max2] = 0;
   }

   for (int i = 0; i < size; i++)
   {
      printf("%d ", arr2[i]);
   }
}