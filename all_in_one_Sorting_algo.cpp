#include <bits/stdc++.h>
using namespace std;

template<class t>void swap(t *a , t *b){
    t temp = *a;
    *a = *b;
    *b = temp;
}

template< class t > void bubbleSort(vector<t> &arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
      }
      cout<<endl;
}

template< class t > void selectionSort(vector<t> &arr,int n){
    for(int i=0;i<n-1;i++){
      int temp = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[temp]){
               temp = j;
            }
        }
        if(temp!=i){
            swap(&arr[i],&arr[temp]);
        }
    }
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}

template<class t>void shellSort(vector<t> &arr, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i ++){
            t temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
               arr[j] = arr[j -gap];
            }
            arr[j] = temp;
        }
    }
    for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
      }
      cout<<endl;
}

template<class t>void sortFunc(vector<t>&vec,int n){
     cout<<"1.] Bubble Sort"<<endl;
     cout<<"2.] Selection Sort"<<endl;
     cout<<"3.] Shell Sort"<<endl;
     cout<<"Enter the choice: ";
     int choice;
     cin>>choice;
     switch (choice){
     case 1:
      bubbleSort(vec,n);
      break;

     case 2:
      selectionSort(vec,n);
      break;

      case 3:
      shellSort(vec,n);
      break;

      default: cout<<"u entered a wrong choice"<<endl;
      break;
     }
}

int main()
{
    cout<<"1.] float type"<<endl;
    cout<<"2.] int type"<<endl;
    cout<<"3.] double type"<<endl;
    cout<<"Enter the choice: ";
    int choice,n;
    cin>>choice;
    switch(choice){
      case 1:{
         cout<<"enter the size of the array: ";
         cin>>n;
         vector<float>vec1;
         for(int i=0;i<n;i++){
            cin>>vec1[i];
         }
         sortFunc(vec1,n);
         break;
      }

      case 2:{
         cout<<"enter the size of the array: ";
         cin>>n;
         vector<int>vec2(n,0);
         for(int i=0;i<n;i++){
            cin>>vec2[i];
         }
         sortFunc(vec2,n);
         break;
      }

      case 3:{
         cout<<"enter the size of the array: ";
         cin>>n;
         vector<int>vec3(n,0);
         for(int i=0;i<n;i++){
            cin>>vec3[i];
         }
         sortFunc(vec3,n);
         break;
      }

      default:cout<<"enter a right choice"<<endl;
      break;
    }

    return 0;
}
