#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
};


struct node* rotate(struct node*node1)
{
    struct node* ptr=node1;
    struct node* ptr2=NULL;
    struct node* temp;
    while(1){
     if(node1->Next==NULL)
     {
         ptr->Next=ptr2;
         return node1;
     }
     temp=ptr->Next;
     ptr->Next=ptr2;
     node1=temp;
     ptr2=ptr;
     ptr=node1;
    }
}

void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->Next;
    }
}

struct node* merge(int data)
{
    int total;
    struct node* node3= NULL;
    struct node*ptr2=NULL;
    while(data!=0)
    {
        total=data%10;
        data=data/10;
        struct node*ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=total;
        ptr->Next=NULL;
        /* if(node3==NULL)
         {
             node3=ptr;
             ptr2=node3;
         } */
        ptr->Next=node3;
        node3=ptr;
    }
    return node3;
}

void multiply(struct node*node1,struct node*node2)
{
  //  printf("b");
    int data;
    int multi1=0;
    int multi2=0;
    int total=1;
    node1=rotate(node1);
    node2=rotate(node2);
    while(node1!=NULL)
    {
        //printf("c");
        multi1=multi1+node1->data*total;
        total=total*10;
        node1=node1->Next;
    }
    total=1;
    while(node2!=NULL)
    {
        multi2=multi2+(node2->data*total);
        total=total*10;
         node2=node2->Next;
    }
    data=multi1*multi2;
    struct node*node3=merge(data);
    print(node3);
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
    head1->data=1 ;
    head1->Next=second1;

    // Link second and third nodes
    second1->data=2;
    second1->Next=third1;


    // Terminate the list at the third node
    third1->data=3;
    third1->Next=forth1;

    forth1->data=4;
    forth1->Next=NULL;


    struct node *head2;
    struct node *second2;
    struct node *third2;
    struct node *forth2;

    // Allocate memory for nodes in the linked list in Heap
    head2 = (struct node*)malloc(sizeof(struct node));
    second2= (struct node*)malloc(sizeof(struct node));
    third2= (struct node*)malloc(sizeof(struct node));
    forth2= (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head2->data=4 ;
    head2->Next=second2;

    // Link second and third nodes
    second2->data=6;
    second2->Next=third2;


    // Terminate the list at the third node
    third2->data=4;
    third2->Next=forth2;

    forth2->data=5;
    forth2->Next=NULL;

//printf("a");
    multiply(head1,head2);


}
