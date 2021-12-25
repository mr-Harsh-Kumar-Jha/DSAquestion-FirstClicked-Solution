#include<stdio.h>
   /*int max=0;
   int min=21345667;  */
   int min2=233455;
void recurse(int arr[],int a[],int j,int N,int k)
{
    if(j>=N)
    {
       int max=0;
       int min =24335454;
        int i;
        for(i=0;i<N;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
            }
            if(a[i]<min)
            {
                min=a[i];

            }
        }
        printf("%d,%d\n",max,min);
        int data=max-min;
        if(data<min2)
        {
            min2=data;
        }
        printf("%d\n",min2) ;
        return;
    }
    a[j]=arr[j]-k;
    if(a[j]>0)
    {
        recurse(arr,a,j+1,N,k);
    }
    a[j]=arr[j]+k;
    recurse(arr,a,j+1,N,k);

}

int main(){
    int arr[4]={3,4,5,0};
    int a[4];
    recurse(arr,a,0,4,3);
    printf("%d",min2);
}
