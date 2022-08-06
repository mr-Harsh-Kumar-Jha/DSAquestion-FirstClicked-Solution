#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& num){
        vector<int>ans;
        int x=0;
        for(auto it: num){
          x^=it;
        }
        int finding_right_most_bit_position = x & ~(x-1);  // to find the right most position of the bit in the xored element in order to divide the whole array into two parts 1.] in which only those elements are present whose bit is not set at the position of the rightmost bit of x   2.] in which only those elements are present  whose bit is set at the position of the rightmost bit of x.
        int z=0 ,y=0;
        for(int i=0;i<num.size();i++){
           if(num[i] & finding_right_most_bit_position){
              z^=num[i];
           }
           else{
            y^=num[i];
           }
        }

        ans.push_back(z);
        ans.push_back(y);
        return ans;
}


int main(){
   int N;
   cin>>N;
   vector<int>num;
   for(int i=0;i<((2*N) + 2);i++){
      int a;
      cin>>a;
      num.push_back(a);
   }
   vector<int> arr = solve(num);
   cout<<arr[0]<<" "<<arr[1]<<endl;
}