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

int searchpairs(int arr[],int size,int diff)  // searching optimization can be done. O(nˆ2);
{
    int i=0;
    int j;
    int b=0;
    while(i!=size)
    {
        j=size-1;
        int sudoadd=diff+arr[i];
        while(arr[j]>=sudoadd)
        {
            if(arr[j]==sudoadd)
            {
                b=b+1;   
                printf("%d , %d\n",arr[i],arr[j]);
            }
            j--;
        }
        i++;
    }
    if(b>0)
    {
      return 1;
    }
    else 
      return 0;
}

int main()
{
   int arr[]={5,20,17,2,6,80};
   int size=sizeof(arr)/sizeof(int);
   int diff=10;
   sort(arr,size);
   int k=searchpairs(arr,size,diff);
   if(k==0)
     printf("no such pair exist");
}