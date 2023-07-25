#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int moding(int a, int b){
   return ((a % mod) * (b % mod)) % mod;
}

int bitSet(int a, int b){
   if (b == 0)
      return 1;
   int temp = bitSet(a, b / 2);
   temp = moding(temp, temp);
   if (b % 2)
      return moding(temp, a);
   return temp;
}

// int mi(int a, int m = mod){
//    return bitSet(a, m - 2);
// }

void Nfact(int fact[] , int ifact[]){
   fact[0] = ifact[0] = 1;
   for (int i = 1; i < 2e5 + 1; i++)
   {
      fact[i] = moding(fact[i - 1], i);
      ifact[i] = moding(ifact[i - 1], bitSet(i , mod-2));
   }
}

signed main(){
   int totalSize =2e5 + 1;
   int fact[totalSize], ifact[totalSize];
   Nfact(fact , ifact);
   int t;
   cin >> t;
   while (t--){
       int n;
      string k, j;
      cin >> n >> k >> j;
      int count = 0;
      for (int i = 0; i < n; i++){
         if (k[i] == j[i])
            count++;
      }
      if ((n - count) % 2){

         cout << 0 << endl;
         continue;
      }
      n -= count;
      int flag = bitSet(2, count);
      flag = moding(flag, moding(fact[n], moding(ifact[n / 2], ifact[n / 2])));
      cout << flag << endl; 
   }
   return 0;
}