//one of the worst solution its time complexity and space complexity is worst as it is complete recurssion so it is trying every possibilities . Its time complexity is un expected

#include<bits/stdc++.h>

using namespace std;

int mine = INT_MAX;
int cnt =0,ctn=0;
int solve(vector<int>coins , int amount){
     if(amount == 0) return 0;
     if(amount<0) return -1;
     for(int i=0;i<coins.size();i++){
        cnt+=1;
        ctn+=1;
       int ans =  solve(coins , (amount - coins[i]));
        if(ans == 0 && cnt<mine){
               mine = cnt;
        }
        cnt--;
     }
     return -1;
}

int main(){
   vector<int>coins{1,2,3,5};
   int amount ;
   cin>>amount;
   solve(coins , amount);
   cout<<mine<<endl;
   cout<<ctn<<endl;
}
