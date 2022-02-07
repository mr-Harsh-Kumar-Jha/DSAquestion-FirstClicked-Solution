#include <bits/stdc++.h>
using namespace std;

void recurse(int arr[],int size ,int count, int& min){
    int *temp=new int[size-1];
    int b=0;
    int k=0;
    if(size<=1){
        if(count<min){
            min=count;
        }
        return;
    }
    sort(arr,arr+size);
    for(int i=0;i<size-1;i++){
        if(arr[i]==arr[i+1]){
            b=b+1;
        }
        else{
            break;
        }
    }
    if(b==size-1){
        if(count<min){
            min=count;
            return;
        }
    }
    for(int i=0;i<size;i++){
        // count=0;
        if(i!=size-1){
          temp[i]=arr[i]+arr[i+1];
        k=i+1;
        for(int j=i+2;j<size;j++){
            temp[k]=arr[j];
            k+=1;
        }
        }
        recurse(temp,size-1,count+1,min);
        temp[i]=arr[i];
    }

}

int main() {
	int t;
	int size;

	int min;
      // cout<<"hi"<<endl;
	cin>>t;
	while(t--){
      min=INT_MAX;
	    cin>>size;
	    int *arr=new int[size];
	    for(int i=0;i<size;i++){
	        cin>>arr[i];
	    }
	   // cout<<"hi"<<endl;
	    recurse(arr,size,0,min);
	    cout<<min<<endl;
	}
	return 0;
}
