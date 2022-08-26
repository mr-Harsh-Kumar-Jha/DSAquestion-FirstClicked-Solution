// fastest solution

#include<bits/stdc++.h>
using namespace std;

 vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri(numRows);
        for(int i=0;i<numRows;i++){
            pasTri[i].resize(i+1); // resizing column for each row = (row+1);
            pasTri[i][0] =1; pasTri[i][i]=1;
            for(int j=1;j<i;j++){
                pasTri[i][j]=pasTri[i-1][j-1]+pasTri[i-1][j];
            }
        }
        return pasTri;
    }

    int main(){
      int n;
      cin>>n;
      vector<vector<int>>ans = generate(n);
      cout<<'[';
      for(int i=0;i<ans.size();i++){
         cout<<'[';
         for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<",";
         }
         cout<<']'<<" ";
      }
      cout<<']'<<endl;
    }