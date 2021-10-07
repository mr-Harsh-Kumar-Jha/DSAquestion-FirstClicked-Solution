#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
};


struct node* divide(struct node*node1,int n)
{
    int count=0;
    int i=0;
    struct node*ptr=node1;
    while(ptr!=NULL)
    {
         count=count+1;
         ptr=ptr->Next;
    }
    ptr=node1;
    while(i!=count-n)
    {
        ptr=ptr->Next;
        i=i+1;
    }
    printf("%d",ptr->data);
}

int main()
{
    struct node *head1;
    struct node *second1;
    struct node *third1;
    struct node *forth1;
    struct node *fifth1;
    struct node *sixth1;

    // Allocate memory for nodes in the linked list in Heap
    head1 = (struct node*)malloc(sizeof(struct node));
    second1= (struct node*)malloc(sizeof(struct node));
    third1= (struct node*)malloc(sizeof(struct node));
    forth1 = (struct node*)malloc(sizeof(struct node));
    fifth1 = (struct node*)malloc(sizeof(struct node));
    sixth1 = (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head1->data=1;
    head1->Next=second1;

    // Link second and third nodes
    second1->data=8;
    second1->Next=third1;


    // Terminate the list at the third node
    third1->data=6;
    third1->Next=forth1;

    forth1->data=2;
    forth1->Next=fifth1;

    fifth1->data=6;
    fifth1->Next=sixth1;

    sixth1->data=9;
    sixth1->Next=NULL;

    int n;

    printf("enter the place of which u want to find element");
    scanf("%d",&n);

    // printf("a");
    divide(head1,n);

}

