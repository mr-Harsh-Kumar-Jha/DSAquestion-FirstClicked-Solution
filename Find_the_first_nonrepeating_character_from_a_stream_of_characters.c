#include<stdio.h>
#include<stdlib.h>


struct node{
   char data;
   struct node* Next; 
};

void nonrepeating(struct node* root)
{
    
   struct node* linked=root;
   struct node* prev=NULL;
   struct node* firstnonrepeating;

   while(linked!=NULL)
   {
       if(prev==NULL)
       {
           firstnonrepeating=linked;
           prev=linked;
           linked=linked->Next;
           printf("%c",firstnonrepeating->data);
       }
       if(linked->data!=prev->data)
       {
            printf("%c",firstnonrepeating->data);
            prev=linked;
            linked=linked->Next;
       }
       else
       {
           printf("#");
           prev=linked;
           linked=linked->Next;

           if(linked!=NULL && prev->data != linked->data)
           {
               firstnonrepeating=linked;
           }
       }
   }
   printf("\t");
}

int main()
{
     struct node* Head;
     struct node* second;
      struct node* third;
      struct node* forth;
     struct node* fifth;

     Head=(struct node*)malloc(sizeof(struct node));
     second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
     forth=(struct node*)malloc(sizeof(struct node));
     fifth=(struct node*)malloc(sizeof(struct node));

    Head->data='a';
    Head->Next=second;

    second->data='b';
    second->Next=third;
 
    third->data='c';
    third->Next=forth;

    forth->data='c';
    forth->Next=fifth;

    fifth->data='b';
    fifth->Next=NULL;
    
     nonrepeating(Head);
}