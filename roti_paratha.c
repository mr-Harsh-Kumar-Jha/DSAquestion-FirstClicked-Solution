#include<stdio.h>

void minimumtime(int rank[],int totchef,int order)
{
   int i=1;// this acts as a clock .
   int paratha=0;
   int j=0; //this will increment condition of  no. of chef (as total cases)
   int total[]={1,1,1,1}; // it is storing the time taken by chef after making each paratha
   int total1[]={1,1,1,1}; //it is storing the total time taken by chef till current going timme. 

   while(paratha<order)
   {
       //printf("%d ",i);
       while(j!=totchef)
       {
        // printf("b");
           if(i==total1[j])
           {
               //printf("a\n");
               total1[j]=total1[j]+rank[j]+total[j];
                // printf("%d",total1[0]);
                // printf("%d\n",total1[1]);
               total[j]=total[j]+rank[j];   
               paratha+=1;

           }
           j++;
       }
       j=0;
       i++;
       // printf("%d",i);
   }
    printf("%d\n",i-1);
}
  

int main()
{
    int rank[]={1,1,1,1};
    int totchef=sizeof(rank)/sizeof(int);

    int order=8 ;

    minimumtime(rank,totchef,order);

}