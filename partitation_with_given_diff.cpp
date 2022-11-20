//Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

//Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

//If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:
            //1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
            // 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
            // Refer to the example below for clarification.

//-----------------------------------------------------------------------------------

//this is a recursive approach and time complexity of the solution is exponential and space complexity of the solution is stack space .

#include<bits/stdc++.h>
using namespace std;

int partGivenDiff(vector<int>&vec , int n , int target){
     if(target == 0) return 1;
     if(n==0) return vec[0]==target;
     int noTake = partGivenDiff(vec,n-1 , target);
     int take = 0;
     if(vec[n]<=target) take = partGivenDiff(vec,n-1,target-vec[n]);
     return noTake | take;
}

int main(){
   vector<int>vec{1,3,2,4,6};
   int n = vec.size();
   int diff = 2;
   int total = 0;
   for(int i=0;i<n;i++){
         total+=vec[i];
   }
   if((total+diff)%2==0){
      int target = (total+diff)/2;
      cout<<partGivenDiff(vec,n-1,target)<<endl;
   }
   else cout<<0<<endl;

}