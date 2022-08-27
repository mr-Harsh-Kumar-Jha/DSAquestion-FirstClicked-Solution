#include <bits/stdc++.h>
using namespace std;

double epsx = 1e-7; // this is used to decide accuracy

int main()
{
   double n;
   cin>>n;

   double  low = 1,high = n;
   double mid;
   while (high - low > epsx)
   {
       mid = (high+low) / 2;
      if ((mid * mid) < n)
      {
         low = mid;
      }
      else
      {
         high = mid;
      }
   }
   cout <<setprecision(10)<< low << endl; // this is used to decide precision .
}