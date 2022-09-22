//`This is a space optimization code for Maximum sum problem and it far most optimised code as its space complexity is O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>vec{1,3,2,5,9,6};
    int prev2=vec[0];
    int prev = 0;
    for(int i=1;i<vec.size();i++){
        int take = vec[i];
        if(i>1) take+=prev2;
        int nTake = 0 + prev;
        int cur = max(take,nTake);
        prev2=prev;
        prev = cur;
    }
    cout<<prev<<endl;
}