#include<stdio.h>
#include<limits.h>

int minArray_1[5];
int minArray_2[5];
int min=12345678;

//in order to make customisible soln just make the above soln in  struct so that u can define customisible minArray.
/*struct storage{
  int* minArray_1;
  int* minArray_2;
  int min;
  int capacity;
}
//constructor function to give size to storage array
struct storage* makeArray(struct node* array ,int min , int a)
{
 if(a==1)
   array->minArray_1=(int*)malloc(array->capacity*sizeof(int));
 else if(a==2)
   array->minArray_2=(int*)malloc(array->capacity*sizeof(int));

   return array;
}*/

void checkout(int arr1[], int arr[] ){
 int sum1,sum2,j,i,min_sum1,min_sum2,k;
 sum1=sum2=k=0;
 for(j=0;j<5;j++)
 {
    sum1=sum1+arr1[j];
 }
 for(i=0;i<10;i++)
 {
   if(arr[i]!=INT_MIN)
   {
     sum2=sum2+arr[i];
   }
 }
 min_sum1=sum1-sum2;
 min_sum2=sum2-sum1;
 if((sum1>=sum2 && min_sum1<min) || (sum2>=sum1 && min_sum2<min))
 {
    while(k<5)
    {
       minArray_1[k]=arr1[k];
       k++;
    }
    k=0;
    for(i=0;i<10;i++)
    { 
       if(arr[i]!=INT_MIN)//yaha problem hain due to which jo 0 pahle se present hain wse hum access nahi kar pa rahe hain therefor ek bahut bada negative assign kar diya jo koi adchan nahi dal paye.
       {
          minArray_2[k]=arr[i];
          k++;
       }
    }
 }
 if(sum1>sum2 && min_sum1<min)
   min=min_sum1;
 else if(sum2>sum1 && min_sum2<min)
   min=min_sum2;
   else if(sum1==sum2)
      min=min_sum1;
}

void recurse(int arr1[], int arr[], int i, int j )
{
    for(;i<10;i++)
    {
    //  printf("%d\n",i);
     if(j>=5)
        return;
     arr1[j]=arr[i];
    //  printf("arr1= ");
    //  for(int k=0;k<5;k++)
    // {
    //  printf("%d",arr1[k]);
    //  printf(",");
    // }
    // printf("\n");
     arr[i]=INT_MIN;
     recurse(arr1,arr,i+1,j+1);
     checkout(arr1,arr);
    // for(int k=0;k<5;k++)
    // {
    //  printf("%d",arr1[k]);
    //  printf(",");
    // }
    // printf("\n");
    // printf("min=%d",min);
    // printf("\n");
    // for(int k=0;k<5;k++)
    // {
    //  printf("%d",minArray_2[k]);
    //  printf(",");
    // }
    // printf("\n\n");
     arr[i]=arr1[j];
    //  printf("%d,%d",arr[i],i);
    //  printf("\n");
    }
}

int main()
{
   
   int arr1[5];
   int arr[]={3, 4, 5, 0, 100, 1, 89, 54, 23, 20};
   int i,j;
   i=j=0;
   recurse(arr1,arr,i,j); 
   printf("%d",min);
   printf("\n");
   for(i=0;i<5;i++)
   {
    printf("%d",minArray_1[i]);
    printf(",");
   }
   printf("\n");
   for(i=0;i<5;i++)
   {
    printf("%d",minArray_2[i]);
    printf(",");
   }
}