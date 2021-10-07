#include<stdio.h>
#include<stdlib.h>

 int top=-1;

struct stacknode
{
    int data;
    struct stacknode* arr;
};

 void push(int item)
    {
        if(isfull(top))
        {
            printf("stack over flown:");
        }
        else
        {
            top++;
            arr[top]=item;
            printf("your item is pushed: ");
        }

    }

    int isfull(int top)
    {
        if(top==(capacity-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isempty(int top)
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int pop(int top)
    {
        if(isempty(top))
        {
            printf("stack is underflow: ");
        }
        else
        {
            return stack[top--];
        }
    }

int termfinder(int a[],int size,int t)
{
    struct stacknode* p=(struct stacknode*)malloc(t*sizeof(struct stacknode));

}

int main()
{
     int array[50];
     int n,i;

     printf("Enter the size of array : ");
     scanf("%d",&n);

     printf("Please enter ur array....\n ");
     for(i=0;i<n;i++)
     {
         printf("array[%d]",i);
         scanf("%d",&array[i]);
     }

     int t;
     printf("enter the term no of which u want to find minima : ");
     scanf("%d",&t);

     termfinder(array,n,t);
}
