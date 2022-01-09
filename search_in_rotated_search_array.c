#include<stdio.h>

int searching(int arr[],int low,int high,int target){
   //printf("b");
  // printf("\n%d\n",low);
   //printf("\n%d\n",high);
      int mid=(low+high)/2;
      if(arr[mid]==target)
      {
           return mid;
      }
      if(target > arr[mid])
      {
          low=mid+1;
          return searching(arr,low,high,target) ;
      }
      else
      {
          high=mid;
          return searching(arr,low,high,target)  ;
      }
      return -1;
}

int search(int arr[],int size,int target)
{
   // printf("a");
     int high=size-1;
     int low=0;
     int pivot=(low+high)/2;
     if (arr[pivot]==target)
     {
         return pivot;
     }
     if(arr[low]==target)
     {
         return low;
     }
     if(arr[high]==target)
     {
         return high;
     }
     if(target>arr[low]&&target<arr[pivot])
     {
       //  printf("b");

       //  printf("%d",low);

         high=pivot;

       //  printf("%d",high);
         return searching(arr,low,high,target);
     }
     else if(target<arr[high]&&arr[pivot]>target)
     {
            //printf("b");
         low=pivot+1;
         return searching(arr,low,high,target);
     }
     else if(target>arr[pivot]&&arr[high]<target)
     {
         //printf("%d",low);
           // printf("b");
       // printf("%d",high);
         low=pivot+1;
        return searching(arr,low,high,target);
     }

}

int main()
{
    int arr[]={4,5,6,7,0,1,2};
    int size=sizeof(arr)/sizeof(int);
    int target=0;
    int item=search(arr,size,target);
    printf("%d",item+1) ;
}

