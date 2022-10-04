#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int n,int m){
   if(n==0 && m==0) return 1;
   if(n<0 || m<0) return 0;
   int left = totalUniquePath(n-1,m);
   int up = totalUniquePath(n,m-1);
   return left+up;
}

int main(){
   int n,m;
   cin>>n>>m;
   cout<<totalUniquePath(n-1,m-1)<<endl;
}