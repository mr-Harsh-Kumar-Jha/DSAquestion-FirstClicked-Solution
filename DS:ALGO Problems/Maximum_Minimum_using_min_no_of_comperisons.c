#include<stdio.h>

void compare(int arr[],int size,int max,int min)
{
    int i=0;
    while(i<size){
        if(arr[i]>arr[i+1] && i<size)
        {
            if(arr[i]>max)
                max=arr[i];
            if(arr[i+1]<min)    
                min=arr[i+1];

            i=i+2;
        }
        else
        {
            if(arr[i]<min)    
                min=arr[i];
            if(arr[i+1]>max)
                max=arr[i+1];
           i=i+2;
        }
    }
    printf("max=%d\n",max);
    printf("min=%d\n",min);
}

int main()
{
    int arr[]={15,22,16,28};
    int size=sizeof(arr)/sizeof(int);
    int max=-435677;
    int min=45323;

    compare(arr,size,max,min);
}