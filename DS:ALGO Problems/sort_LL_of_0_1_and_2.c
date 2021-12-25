#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
};

void print(struct node*root)
{
    struct node*ptr=root;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->Next;
    }
    return;
}

int sort(struct node* root)
{
    struct node*ptr=root;
    struct node*ptr2=root->Next;
    struct node*prev;
    int a=0;
    while(ptr2!=NULL && ptr!=NULL)
    {
        //printf("b\n");
       // printf("%d\t",ptr2->data);
        if(ptr2==ptr && ptr2->data==1)
        {
            //printf("b");
            // ptr=ptr->Next;
            ptr2=ptr->Next;

        }
        else if(ptr2==ptr)
        {
           // printf("m");
            prev=ptr;
           // ptr=ptr->Next;
            ptr2=ptr->Next;
            a=a+1;
        }

        while(/*cond1*/(ptr2!=NULL&&ptr!=NULL)&&/*cond2*/(ptr2->data) >=(ptr->data))   // on placing cond2 in place of cond1 it was trying to access null pointer as on placing it in its deserved place removes segmentation error as when ptr and ptr2 was NULL they were accessing NULL pointer which made them captured in memory only this is segmentation error.
        {
            //printf("d\n");
            ptr2=ptr2->Next;
            if(ptr2==NULL) {
                prev=ptr;
               ptr=ptr->Next;
               ptr2=ptr->Next;
            }
          //  printf("%d",ptr->data);
        }
        //printf("%d",ptr->data);
        if(ptr2!=NULL &&ptr!=NULL)
        {
            //printf("k");
            struct node*temp=ptr2->Next;
            ptr2->Next=ptr;
            ptr=ptr->Next;
            if(a<1)
            {
                root=ptr;
            }
            if(a>0)
            {
                prev->Next=ptr;
            }
            ptr2->Next->Next=temp;
           /* printf("%d",root->data);
            printf("%d",root->Next->data);
            printf("%d",root->Next->Next->data);
            printf("d\n");  */
       }
      // print(root);
      //  printf("c");
      //  printf("\n");

        /* struct node*ptr4=root;
         while(ptr4!=NULL)
         {
             printf("%d",ptr->data);
             ptr4=ptr4->Next;
         }
         printf("\n"); */
    }
   // printf("e");
    print(root);
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    forth = (struct node*)malloc(sizeof(struct node));
    fifth = (struct node*)malloc(sizeof(struct node));
    sixth = (struct node*)malloc(sizeof(struct node));
    seventh = (struct node*)malloc(sizeof(struct node));

    // Link first and second nodes
    head->data=1 ;
    head->Next=second;

    // Link second and third nodes
    second->data=2;
    second->Next=third;


    // Terminate the list at the third node
    third->data=0;
    third->Next=forth;

    forth->data=1;
    forth->Next=fifth;


    fifth->data=0;
    fifth->Next=sixth;



    sixth->data=2;
    sixth->Next=seventh;



    seventh->data=0;
    seventh->Next=NULL;


    /*  struct node*ptr=head;
      while(ptr!=NULL)
      {
          printf("%d\n",ptr->data);
          ptr=ptr->Next;
      }
       */
    sort(head);
}
