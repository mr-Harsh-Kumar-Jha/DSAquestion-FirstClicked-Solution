#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node * Next;
};

void find_first_common_point(struct node* root1, struct node* root2)
{
 int a=0;
    while(root1!=NULL && root2!=NULL)
    {
         if(root1->data < root2->data)
         {
              root1=root1->Next;
         }
         else if(root2->data < root1->data)
         {
              root2=root2->Next;
         }
         else if(root2->data == root1->data)
         {
              a=a+1;
              printf("%d",root1->data);
              break;
         }
    }
    if(a==0)
    {
         printf("there is no such common point");
    }
}

int main()
{
      struct node* Head1;
     struct node* second1;
      struct node* third1;
      struct node* forth1;
     struct node* fifth1;
    // struct node* sixth1;

     Head1=(struct node*)malloc(sizeof(struct node));
     second1=(struct node*)malloc(sizeof(struct node));
    third1=(struct node*)malloc(sizeof(struct node));
     forth1=(struct node*)malloc(sizeof(struct node));
     fifth1=(struct node*)malloc(sizeof(struct node));
      //  sixth1=(struct node*)malloc(sizeof(struct node));

    Head1->data=3;
    Head1->Next=second1;

    second1->data=6;
    second1->Next=third1;
 
    third1->data=9;
    third1->Next=forth1;

    forth1->data=15;
    forth1->Next=fifth1;

    fifth1->data=30;
    fifth1->Next=NULL;


    struct node* Head2;
     struct node* second2;
      struct node* third2;
      struct node* forth2;
     struct node* fifth2;
    // struct node* sixth2;

     Head2=(struct node*)malloc(sizeof(struct node));
     second2=(struct node*)malloc(sizeof(struct node));
    third2=(struct node*)malloc(sizeof(struct node));
     forth2=(struct node*)malloc(sizeof(struct node));
     // fifth2=(struct node*)malloc(sizeof(struct node));
    // sixth2=(struct node*)malloc(sizeof(struct node));
    

     Head2->data=10;
     Head2->Next=second2;

    second2->data=15;
    second2->Next=third2;
 
    third2->data=30;
    third2->Next=NULL;

    // forth2->data=40;
    // forth2->Next=NULL;

    // fifth2->data=10;
    // fifth2->Next=sixth2;

    // sixth2->data=22;
    // sixth2->Next=NULL;

    find_first_common_point(Head1 , Head2);
}