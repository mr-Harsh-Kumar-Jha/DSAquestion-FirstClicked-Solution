// Chef has an array A of length N. He defines the alternating sum of the array as:

// S=|A1|−|A2|+|A3|−|A4|+…(−1)N−1⋅|AN|
// Chef is allowed to perform the following operation on the array at most once:

// Choose two indices i and j (1≤i<j≤N) and swap the elements Ai and Aj.
// Find the maximum alternating sum Chef can achieve by performing the operation at most once.

// Note: |X| denotes the absolute value of X. For example, |−4|=4 and |7|=7.

//  # sample input
// 2
// 2
// 10 -10
// 7
// -3 -2 -1 0 1 2 3

//solution : Alternating addition ke case me odd position pe min element present hone chayiea and even position pe max element hoona chayiea

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void swap(ll arr[], int i, int j)
{
   ll temp = arr[i];
   arr[i] = arr[j];
   arr[j] = temp;
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int N;
      cin >> N;
      ll arr[N];
      ll count = 0;

      ll max = INT_MIN;
      int max_;
      ll min1 = INT_MAX;
      int min2;

      int a = 0;

      for (int i = 0; i < N; i++)
      {
         ll am;
         cin >> am;
         arr[i] = abs(am);
         if (i%2!=0 && arr[i] > max)
         {
            max = arr[i];
            max_ = i;
         }
         else if(i%2==0 && arr[i]<min1){
             min1=arr[i];
             min2=i;
         }
      }

     swap(arr, min2, max_);

      for (int i = 0; i < N; i++)
      {
         if (i % 2 != 0)
         {
            count = count - arr[i];
         }
         else
            count = count + arr[i];

      }
      cout<<count << endl;
   }
   return 0;
}
