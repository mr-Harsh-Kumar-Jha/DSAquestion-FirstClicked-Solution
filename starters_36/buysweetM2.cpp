#include <bits/stdc++.h>
using namespace std;
int main() {

    int t;
    cin>>t;
    while(t--){
        int N,R;
        cin>>N>>R;
        vector<int> A(N),B(N);
       int  count=0;
        for(int i=0;i<N;i++){
            cin>>A[i];

        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        vector<int> c(N),M(N);
        for(int i=0;i<N;i++){
            c[i]=A[i]-B[i];
            M[i]=A[i]-B[i];
        }
        sort(M.begin(), M.end());
        for(int i=0;i<N;i++){
            M[i]=find(c.begin(), c.end(), M[i])-c.begin();
        }
        int index=M[0];
        int index2=0;

        while(R>= *min_element (A.begin(), A.end())){
            if(R>=A[index]){
                 R-=(A[index]-B[index]);
                 count=count+1;
            }
            else{
                index2+=1;
                index=M[index2];
            }
        }
        cout<<count<<endl;
    }
}