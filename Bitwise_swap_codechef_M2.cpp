#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &v, int i,int j) {
    int t = v[i];
    v[i]=v[j];
    v[j] = t;
}

int main() {
   //  ios_base::sync_with_stdio(false);
   //  cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> ns(n);
        set<pair<int,int>> ns2;

        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            ns[i] = a;
            ns2.insert({a, i});
        }
        bool pos = true;
        for(int i=0;i<n-1;i++) {
            auto p = ns2.begin();
            auto s = (*p).first;
            int ind = (*p).second;
            if(ind==i) {
                ns2.erase(p);
                continue;
            }
            int o_1 = s;
            int o_2 = ns[i];
            int j=i;
            while(j<n){
                if(o_1 & ns[j]) {
                    o_1 |= ns[j];
                }
                if(o_2 & ns[j]) {
                    o_2 |= ns[j];
                }
                if(o_1 & o_2)
                    break;
                j++;
            }
            if(j==n){
                pos=false;
                cout<<"NO\n";
                break;
            } else {
                swap(ns, i, ind);
                ns2.erase(p);
                ns2.erase({ns[ind], i});
                ns2.insert({ns[ind], ind});
            }
        }
        if(pos)
            cout<<"YES\n";
    }
}