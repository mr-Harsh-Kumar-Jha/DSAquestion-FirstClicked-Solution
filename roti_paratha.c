#include<stdio.h>

int max(int total[],int no_of_chef)
{
    int max1=0;
    for(int i=0;i<no_of_chef;i++)
    {
       if(total[i]>max1)
       {
          max1=total[i];
       }
    }
    return(max1);
}

void min_time(int time_taken_by_each_chef[],int no_of_chef,int order)
{
   int i=1;
   int paratha=0;
   int j=0;
   int total[]={1,2};
   int total1[]={1,2};

   while(paratha!=order)
   {
       while(j!=no_of_chef)
       {
           if(i==time_taken_by_each_chef[j])
           {
               paratha+=1;
               total1[j]=total1[j]+time_taken_by_each_chef[j]+total[j];
               total[j]=total[j]+time_taken_by_each_chef[j];               
           }
           j=j+1;
       }
       j=0;
       i=i+1;
       // printf("%d",i);
   }
  
int max1 = max(total,no_of_chef);
  printf("%d",max1);
}

int main()
{
    int time_taken_by_each_chef[]={1,2};
    int no_of_chef=sizeof(time_taken_by_each_chef)/sizeof(int);

    int no_of_paratha_ordered=8;

    min_time(time_taken_by_each_chef,no_of_chef,no_of_paratha_ordered);

}