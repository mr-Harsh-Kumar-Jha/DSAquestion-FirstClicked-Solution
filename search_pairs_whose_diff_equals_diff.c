#include<stdio.h>

void swap(int arr[],int i,int j)
{
  int temp=arr[j];
  arr[j]=arr[i];
  arr[i]=temp;
}

void sort(int arr[],int size)   //sorting optimization can be done.;
{
   for (int i=0;i<size;i++)
   {
      for(int j=i+1;j<size;j++)
      {
         if(arr[i]>arr[j])
         {
            swap(arr,i,j);
         }
      }
   }
}

void searchpairs(int arr[],int size,int diff)  // searching optimization can be done. O(nˆ2);
{
    int i=0;
    int j;
    while(i!=size)
    {
        j=size-1;
        int sudoadd=diff+arr[i];
        while(arr[j]>=sudoadd)
        {
            if(arr[j]==sudoadd)
            {
                printf("%d , %d\n",arr[i],arr[j]);
            }
            j--;
        }
        i++;
    }
}

int main()
{
   int arr[]={5,20,17,2,6,80};
   int size=sizeof(arr)/sizeof(int);
   int diff=11;
   sort(arr,size);
   searchpairs(arr,size,diff);
}