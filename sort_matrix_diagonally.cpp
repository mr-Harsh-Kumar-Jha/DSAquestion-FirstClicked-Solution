#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> sort( vector<vector<int>>arr)
{
   int j;
   int k,l=0,m=0,min_idx1 , min_idx2,n=0;
      for(int i=0;i<arr.size();i++){
         // for( i>0?j =0:j=arr[0].size()-1;j>=0;j--){
            m=i;
            k=i;
            min_idx1=i;
             while(m!=arr.size()){
               l=m+1;
               min_idx2=m;
               while(k!=arr.size()){
                   if (arr[k][l] < arr[min_idx1][min_idx2]){
                     min_idx1 = 45;
                     min_idx2 =65;
                   }

               }
             }
         // }
      }
}

int main()
{
   vector<vector<int>> arr{
       {10, 30, 45, 40},
       {29, 37, 20, 45},
       {27, 15, 25, 1},
   };
   arr =sort(arr);
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         cout << arr[i][j];
      }
      cout << endl;
   }
}