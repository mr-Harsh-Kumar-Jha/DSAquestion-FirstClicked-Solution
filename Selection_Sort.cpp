#include <bits/stdc++.h>
using namespace std;

template<class t>void swap(t *a , t *b){
    t temp = *a;
    *a = *b;
    *b = temp;
}

template< class t > void selectionSort(t arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
