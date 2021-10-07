#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
};


struct node* divide(struct node*node1)
{
    // printf("b");
    struct node* ptr=node1;
    struct node* tempev=NULL;
    struct node* tempodd=NULL;
    struct node* prev=NULL;
    struct node* prev2=NULL;
    struct node* ptr2;
    struct node* ptr1;
    int count=0;

    while(ptr!=NULL)
    {
       // printf("\nc");
        if((ptr->data)%2==0 && tempodd==NULL)
        {
            prev2=ptr;
            //printf("d");

        }
        else if(ptr->Next!=NULL&&(ptr->Next->data)%2==0 && tempodd!=NULL)
        {
            prev=ptr;
            tempev=ptr->Next;
           // printf("%d",prev->data);
           // printf("e");

        }
        else if((ptr->data)%2!=0 && tempodd==NULL)
        {
           // printf("f");
            tempodd=ptr;

        }

        if(tempev!=NULL)
        {
            count=count+1;
            ptr2=tempodd->Next;
           // printf("%d",tempodd->data);
            ptr1=tempev->Next;
            if(prev2!=NULL)
            {
                prev2->Next=tempev;
            }
            else
            {
                node1=tempev;
            }
            tempev->Next=ptr2;
            tempodd->Next=ptr1;
            prev->Next=tempodd;
            if(prev2!=NULL)
            {
                prev2->Next=tempev;
            }
            ptr=tempev;
           // printf("%d",ptr->Next->data);
            tempodd=NULL;
            tempev=NULL;
        }
        if(count==0)
        {
            //printf("k");
            ptr=ptr->Next;
        }
        count=0;
    }
    return node1;
}

void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->Next;
    }
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
    third1->data=5;
    third1->Next=forth1;

    forth1->data=2;
    forth1->Next=fifth1;

    fifth1->data=7;
    fifth1->Next=sixth1;

    sixth1->data=4;
    sixth1->Next=NULL;


    // printf("a");
    head1=divide(head1);

    print(head1);


}
