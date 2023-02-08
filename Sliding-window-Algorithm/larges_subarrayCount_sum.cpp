//this solution will not work for array containing negative elements ,as we can make an observation if the array contains neative elements then all the cases where the sum will be greater than target and the negative elements is present after that the due to third  base condition we can conclude that elemnts will start from (i+1)th index and which will result into missing of the cases . eg vec{3,1,1,1,1,0,0,-1,-2,1,2,3,5} here ans should be 10 but ans is 3 only.

#include<bits/stdc++.h>
using namespace std;

int main(){
   vector<int>vec{3,1,1,1,1,0,0,-1,-2,1,2,1,3,5};
   int i=0 , n=vec.size(),j=0,k=5,sum=0;
   int max=INT_MIN;
   while(j<n){
      if(sum<k){
         sum+=vec[j];
         j++;
      }
     else if(sum==k){
         sum+=vec[j];
         if((j-i)>max){
            max = (j-i);
         }
         j++;
      }
      else if(sum>k){
         sum+=vec[j];
         while(sum>k){
            sum-=vec[i];
            i++;
         }
         j+=1;
      }
   }
   cout<<max<<endl;
}