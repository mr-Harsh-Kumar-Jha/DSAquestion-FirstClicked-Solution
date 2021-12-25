/*find how coins &/ notes are required to have a given amount
     eg. suppose we are given that , we have notes and coins of " rs[1,2,5,10,20,50,100,200,2000] "
     and we are asked to find how many minimum notes /& coins are required to have " Rs.70 " ........(input by user);

     output should be ;
         50 Rs, 20 Rs.;
*/
#include<stdio.h>
#define MAX 1000

int greedy(int arr[],int money,int Tnotes,int size,int min,int max)
{
    int b;
    int a;

    a=(max+min)/2;

    if(Tnotes==1)
    {
        if(money<arr[a])
        {
           return arr[a-1];
        }
        else{
           return arr[a] ;
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
        Tnotes=(Tnotes)/2;
        min=a;

        b=greedy(arr,money,Tnotes,size,min,max);
    }
    else
    {
        Tnotes=(Tnotes)/2;
        max=a;

        b=greedy(arr,money,Tnotes,size,min,max);

    }
    return b;
}

int main()
{
    int array[]= {1,2,5,10,20,50,100,200,500,2000};
    int size=10,i=0;
    int money;
    int max=size;
    int min=0;
    int c[MAX]= {0};

    printf("Enter the money to know which notes /& coins u will be provided: ");
    scanf("%d",&money);

    while(money!=0)
    {
        c[i]=greedy(array,money,size,size,min,max);
        money=money-c[i];
        i++;
    }

     printf("your required no. of notes are: %d\n",i);

    int k;
    printf("Your required notes are.............. \n");
    for(k=0; k<=i-1; k++)
    {
        printf("%d.] Rs. %d\n",k+1,c[k]);
    }

}
