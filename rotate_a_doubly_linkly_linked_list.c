#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node * Next;
     struct node* prev;
};

void print(struct node* root)
{
 struct node* temp=root;
    while(temp!=NULL)
    {
       printf("%d",temp->data);
       temp=temp->Next;
       printf(" ");
    }
}

void rotate(struct node* root)
{
     // printf("b\n");
      int n=1;
      struct node* ptr= root;
      struct node* ptr2=root;
      struct node* prev1;
      struct node* temp3;
      struct node* temp;
      struct node* temp2;
      struct node* head;
      struct node* temp4;
     // struct node* ptr4;
      while(ptr!=NULL)
      {
         // printf("c\n");
            while(ptr2!=NULL && n!=6)
            {
                 // printf("d\n");
                  ptr2=ptr2->Next;
                  n=n+1;
            }
        //    printf("%d",ptr2->data);
            prev1=ptr;
            if(ptr2!=NULL)
                temp3=ptr2->Next;
                
            while(ptr2!=NULL && prev1!=ptr2)
            {
               // printf("f\n");
                temp4=prev1->prev;
                temp=ptr2->Next;
                temp2=prev1->Next;
                
                prev1->prev=ptr2;
                ptr2->Next=prev1;
                prev1->Next=temp;
                if(temp!=NULL)
                    temp->prev=prev1;
                prev1=temp2;
                prev1->prev=temp4;
                if(temp4!=NULL)
                {
                    temp4->Next=prev1;
                }
            }
            if(prev1->prev==NULL)
            {
               // printf("e\n");
                head=prev1;
            }
            if(ptr2==NULL)
            {
                ptr=NULL;
            }
            else{
               ptr2=temp3;
               n=1;
               ptr=ptr2;
            }
            // print(head);
      }
      print(head);
}

int main()
{
    struct node* Head1;
     struct node* second1;
      struct node* third1;
      struct node* forth1;
     struct node* fifth1;
     struct node* sixth1;

     Head1=(struct node*)malloc(sizeof(struct node));
     second1=(struct node*)malloc(sizeof(struct node));
    third1=(struct node*)malloc(sizeof(struct node));
     forth1=(struct node*)malloc(sizeof(struct node));
     fifth1=(struct node*)malloc(sizeof(struct node));
     sixth1=(struct node*)malloc(sizeof(struct node));

    Head1->data=3;
    Head1->Next=second1;
    Head1->prev=NULL;

    second1->data=6;
    second1->Next=third1;
    second1->prev=Head1;
 
    third1->data=9;
    third1->Next=forth1;
    third1->prev=second1;

    forth1->data=15;
    forth1->Next=fifth1;
    forth1->prev=third1;

    fifth1->data=30;
    fifth1->Next=sixth1;
    fifth1->prev=forth1;
    
    sixth1->data=2;
    sixth1->Next=NULL;
    sixth1->prev=fifth1;

    //printf("a");
    rotate(Head1);
}