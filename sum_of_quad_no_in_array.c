#include<stdio.h>

/*void swap(int arr1[],int i,int j)
{
  int temp=arr1[j];
  arr1[j]=arr1[i];
  arr1[i]=temp;
}*/


/*void sort(int arr1[],int size)   //sorting optimization can be done.;
{
   for (int i=0;i<size;i++)
   {
      for(int j=i+1;j<size;j++)
      {
         if(arr1[i]>arr1[j])
         {
            swap(arr1,i,j);
         }
      }
   }
}*/
void  print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
       printf("%d",arr[i]);
    }
    printf("\t");
}

void sort(int arr[],int size)
{
 int temp1;
 int k;
    for (int i=0;i<size;i++)
    {
        temp1=arr[i];
        k=i;
        for(int j=i-1;j>=0;j--)
        {
           if(arr[j]>temp1)
           {
              arr[k]=arr[j];
              k=j;
              
           }
        }
        arr[k]=temp1;
    }
}

void recurse(int arr[], int size, int sum, int data, int arr1[], int j, int k)
{
    int i;
    if(k==4 && sum==data)
    {
     // printf("\n");
      //sort(arr1 , 4);
       for(k=0; k<4; k++)
       {
           //sort(arr1 , 4);
           printf("%d",arr1[k]);
           printf(" ");
       }
       printf("\n");
    }
    else if(k==4 && sum!=data)
    {
        return;
    }

    for(i=j;i<size;i++)
    {
        arr1[k]=arr[i];
        sum=sum+arr1[k];
        recurse(arr,size,sum,data,arr1,++j,k+1);
        sum=sum-arr1[k];
    }
}

int main()
{
    int arr[]={10,2,3,4,5,7,8};
    
    int size=sizeof(arr)/sizeof(int);

    sort(arr,size);
   // print(arr,size);

    int sum=0;
    int data=23;
    int arr1[4];
    int j=0;;
    int k=0;

    recurse(arr,size,sum,data,arr1,j,k);

}