//check sorted array using recurrsion.

#include<iostream>

using namespace std;

bool sortcheck(int arr[],int n)
{
    if(n==1){
        return true;
    }
    bool restarray=sortcheck(arr+1,n-1);

    return (arr[0]<arr[1] && restarray);
}

int main()
{
    int arr[]={1,2,7,4,5,6};
    cout<<sortcheck(arr,6)<<endl;
}
