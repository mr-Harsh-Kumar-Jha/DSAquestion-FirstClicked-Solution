
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['M']=500;

    string s;
    cin>>s;
    int n;
    cin>>n;
    int count=0;
    int sum=0;

    for(int i=0;i<n;i++){
        for(auto it:m){
            if(i+1<n && (s[i]=='I') && (s[i+1]=='V'||s[i+1]=='X')){
                auto itr=m.find(s[i]);
            //   cout<<itr->first<<endl;
                sum=sum-itr->second;
                count++;
                break;
            }
            if(s[i]==it.first ){
                count++;
                sum+=it.second;
                break;
            }
        }
    }
    cout<<sum<<endl;

    return 0;
}
