#include<stdio.h>
#define MAX 10000

//void quick(int,int,int );
//int partition(int*,int,int );

int greedy(int arr[],int money,int Tnotes,int size,int min,int max)
{
    int b;
    int a;

    a=(max+min)/2;

    if(Tnotes==1)
    {
        if(money<arr[a])
        {
            printf("hi\n");
            return arr[a-1];
        }
        else  if(money>arr[a] && a<size-1 && money>arr[a+1] )
        {
            return arr[a+1];
        }
        else
        {
            return arr[a];
        }
    }

    if(arr[a]==money)
    {
        b=arr[a];
        Tnotes=Tnotes/2;
        return b;
    }

    else if(arr[a]<money)
    {
        Tnotes=(Tnotes+1)/2;
        min=a-1+1;

        b=greedy(arr,money,Tnotes,size,min,max);
    }
    else
    {
        Tnotes=(Tnotes)/2;
        max=a-1;

        b=greedy(arr,money,Tnotes,size,min,max);

    }
    return b;
}

int unsorted(int arr[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arr[i]<arr[i+1])
        {
            return 1;
        }
        else
        {
            printf("hi");
            return 0;
        }
    }

}

int quick(int arr[],int low,int high,int b,int n1,int n2)
{
    int j=0;
int c[MAX];
    int partitionIndex,i;

    if(low<high)
    {

        partitionIndex=partition(arr,low,high);

        /*  for(i=0; i<high+1; i++)
          {
              printf("%d",arr[i]);
          }
          printf("\n");*/

        quick(arr,low,partitionIndex-1,b,n1,n2);

        quick(arr,partitionIndex+1,high,b,n1,n2);



    }
    /* while(b!=0 )
        {
            c[j]=greedy(arr,b,n1,n2,0,n1);
            b=b-c[j];
            j++;
        }*/
    int k;
    for(k=0; k<high+1; k++)
    {
        printf("%d\n ",arr[k]);
    }
    return j-1;


}

int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;

    do
    {

        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<j)
        {

            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    while(j>i);

    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;

    return j;
}

int main()
{
    int array[1000];
    int n;
    int b;
    int i;
    int j=0;

    int c[MAX]= {0};

    scanf("%d",&n);
    scanf("%d",&b);

    for(i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }

    if(unsorted(array,n)==1)
    {
        j=quick(array,0,n,b,n,n);
    }
    else
   {
       while(b!=0 )
        {
            c[j]=greedy(array,b,n,n,0,n);
            b=b-c[j];
            j++;
        }
   }

    printf("%d\n\n",j);

   /* int k;
    for(k=0; k<j; k++)
    {
        printf("%d ",c[k]);
    }*/
}


