#include<stdio.h>
#include<stdlib.h>

struct list
{
     int data;
     struct list* next;
};

void enqueue(struct list* f,struct list* r,int a)
{
    struct list* n=(struct list*)malloc(sizeof(struct list));
    if(n==NULL)
    {
        printf("The queue is Full.\n");
    }
    else{
            n->data=a;
            n->next=NULL;
            if(f==NULL)
            {
                f=r=n;
            }
            else{
                  r->next=n;
                  r=n;
            }
    }
}

void traversal(struct list* ptr)
{
    printf("Printing THE ELEMENTS..............\n ");
    while(ptr!=NULL)
    {
        printf("%d\n ",ptr->data);
        ptr=ptr->next;
    }
}
struct list* f=NULL;
struct list* r=NULL;
int main()
{
       enqueue(f,r,34);
       enqueue(f,r,17);
       traversal(f);
}
