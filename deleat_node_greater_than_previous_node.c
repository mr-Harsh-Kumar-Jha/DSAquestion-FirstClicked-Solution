#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
};


struct node* deleat(struct node*node1)
{
    struct node* ptr=node1;
    struct node* ptr2=NULL;
    struct node* temp;
    int count=0;
    while(ptr->Next!=NULL){
     while(ptr->Next->data > ptr->data)
     {
         count=count+1;
         temp=ptr->Next;
         ptr2=temp->Next;
         printf("%d",temp->data);
         free(temp);
         ptr->Next=ptr2;

     }
     ptr=ptr->Next;

    }
    if(count==0)
    {
        printf("No deletion possible");
    }
}


int main()
{
    struct node *head1;
    struct node *second1;
    struct node *third1;
    struct node *forth1;

    // Allocate memory for nodes in the linked list in Heap
    head1 = (struct node*)malloc(sizeof(struct node));
    second1= (struct node*)malloc(sizeof(struct node));
    third1= (struct node*)malloc(sizeof(struct node));
    forth1 = (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head1->data=4 ;
    head1->Next=second1;

    // Link second and third nodes
    second1->data=5;
    second1->Next=third1;


    // Terminate the list at the third node
    third1->data=3;
    third1->Next=forth1;

    forth1->data=2;
    forth1->Next=NULL;

    deleat(head1);


}
