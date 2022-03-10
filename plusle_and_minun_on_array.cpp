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
      int j, k = 1;

      if ((N - 1) % 2 == 0)
         j = N - 1;
      else
         j = N - 2;

      ll max = INT_MIN;
      int max_;
      ll min1 = INT_MAX;
      int min2;
      ll max2 = INT_MIN;
      int max3;
      int a = 0;

      for (int i = 0; i < N; i++)
      {
         ll am;
         cin >> am;
         arr[i] = abs(am);
         if (arr[i] > max)
         {
            max = arr[i];
            max_ = i;
         }
      }
      for (int i = 0; i < N; i += 2)
      {
         if (max_ % 2 != 0 && arr[i] < max)
         {
            swap(arr, 0, max_);
            a = 1;
            break;
         }
      }
      if (a == 0)
      {
         while (k < j)
         {
            if (k % 2 != 0)
            {
               if (arr[k] > max2){
                  max2 = arr[k];
               max3 = k;
               }
            }
            if (j % 2 == 0)
            {
               if (arr[j] < min1 && arr[j] < max2)
               {
                  min1 = arr[j];
                  min2 = j;
               }
            }
            j = j - 2;
            k = k + 2;
         }
         //  cout<<"min2="<<min2<<" "<<"max3="<<max3<<endl;
         swap(arr, min2, max3);
         // for(int i=0;i<N;i++){
         //    cout<<endl<<arr[i]<<" ";
         // }
      }
      for (int i = 0; i < N; i++)
      {
         if (i % 2 != 0)
         {
            count = count - arr[i];
         }
         else
            count = count + arr[i];

            cout<<count<<" ";
      }
      cout<< count << endl;
   }
   return 0;
}
