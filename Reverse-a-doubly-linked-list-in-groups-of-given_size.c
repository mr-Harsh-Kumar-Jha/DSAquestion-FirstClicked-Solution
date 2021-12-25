#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* Next;
    struct node*prev;
};

void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->Next;
    }
}

struct node* divide(struct node*node1,int n)
{
    // printf("\nk");

    int count=1;

    struct node*temp1;
    struct node*temp2;
    struct node*temp3;
    struct node*temp4;
    struct node*ptr=node1;
    struct node*ptr2=node1;
    struct node*ptr3;
    int k=n;
    while(ptr!=NULL)
    {
        //  printf("\nb");
        k=n;
        while(count!=n && ptr->Next!=NULL)
        {

            // printf("c");
            ptr=ptr->Next;
            count=count+1;
        }
        printf("\nptr=%d\t",ptr->data);
        ptr3=ptr->Next;


        while(count==n && ptr2->prev!=ptr && ptr2!=ptr)
        {

            // printf("d");

            temp1=ptr->prev;
            // printf("\nhi=%d\t",temp1->data);
            temp2=ptr->Next;
            temp3=ptr2->prev;
            temp4=ptr2->Next;
            //printf("%d\n",temp3);
            if(ptr2->prev==NULL)
            {

                node1=ptr;
                // printf("head=%d\n",ptr->data);
            }

            if(k>3)
            {
                printf("h\n");
                ptr->Next=ptr2->Next;
                ptr->prev=temp3;
                ptr2->Next=temp2;
                ptr2->prev=temp1;
                k=k-2;
            }
            else
            {
                printf("g\n");
                ptr->Next=temp1;
                ptr->prev=temp3;
                ptr2->prev=temp4;
                ptr2->Next=temp2;
            }
            if(temp3!=NULL)
            {
                printf("hi");
                temp3->Next=ptr;
            }
            if(temp2!=NULL)
                temp2->prev=ptr2;
            if( n==3||k==3 || ptr2->Next==NULL ) {
                temp4->Next=ptr2;
                printf("bye=%d",ptr2->Next->data);
            }

            if(n>=3)
                temp4->prev=ptr;
            // printf("hii=%d\n",ptr->Next->data);
            if(temp1->data==ptr2->data && temp4->data==ptr->data)
            {
               // print(node1);
                ptr=temp4;
                ptr2=temp1;
            }
            else
            {
                if( n>3&&ptr3!=NULL&&ptr3->prev->prev!=NULL )
                    ptr3->prev->prev->Next=ptr2;
                //    print(node1);
              //  printf("k\t");
                ptr=temp1;
                ptr2=temp4;
               // printf("temp1=%d\n",temp1->data);
               // printf("temp4=%d\n",temp4->data);
            }
            /* printf("ptr=%d\n",ptr->data);
            printf("ptr2=%d\n",ptr2->data);  */
            // print(node1);
            //printf("\n");

        }

        ptr2=ptr3;
        ptr=ptr3;
        // printf("\nptraft=%d",ptr->data);
        // printf("\nptr2aft%d",ptr2->data);
        count=1;
    }
    printf("%d",node1->data);
    printf("%d",node1->Next->data);
    printf("%d",node1->Next->Next->data);
    printf("%d",node1->Next->Next->Next->data);
    printf("%d",node1->Next->Next->Next->Next->data);
    printf("%d",node1->Next->Next->Next->Next->Next->data);

    // printf("%d\n",node1->data);
    //  print( node1);
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
    head1->prev=NULL;

    // Link second and third nodes
    second1->data=8;
    second1->Next=third1;
    second1->prev=head1;


    // Terminate the list at the third node
    third1->data=6;
    third1->Next=forth1;
    third1->prev=second1;

    forth1->data=2;
    forth1->Next=fifth1;
    forth1->prev=third1;

    fifth1->data=6;
    fifth1->Next=sixth1;
    fifth1->prev=forth1;

    sixth1->data=9;
    sixth1->Next=NULL;
    sixth1->prev=fifth1;

    printf("a");
    head1= divide(head1,5);

    // print(head1);

}


