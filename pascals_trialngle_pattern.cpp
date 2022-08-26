#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int arr[n][(2*n)-1];
   memset(arr , 0 , sizeof(arr));
   arr[0][n-1]=1;
   for(int i=1;i<n;i++){

      for(int j =n-i-1;j<(2*n)-1;j++){
            if( j-1 <0) arr[i][j]=1;
            else
              arr[i][j]=arr[i-1][j-1]+ (j+1<(2*n)-1?arr[i-1][j+1]:0);
      }
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<(2*n)-1;j++){
         if(arr[i][j]==0) cout<<" ";
         else
           cout<<arr[i][j];
      }
      cout<<endl;
   }
}