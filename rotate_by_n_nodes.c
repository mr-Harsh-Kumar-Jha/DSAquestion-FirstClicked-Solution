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

void rotate(struct node* root,int interval,int size)
{
   // printf("a\n");
    struct node* ptr=root;
    int count=1;
    int interv_length=(size/interval);
    struct node* ptr2[interv_length];
    struct node* temp1;
    struct node* temp2;
    int extra=(size%interval);
    
    if(interv_length==1 || interv_length==0)
    {
        print(root);
        return;
    }
    else
    {
       // printf("b\n");
        int i=0;
        while(ptr!=NULL){
           // printf("c\n");
           ptr2[i]=ptr;
           while(ptr->Next!=NULL && count!=interval)
           {
              // printf("d\n");
               ptr=ptr->Next;
               count=count+1;
           }
           ptr=ptr->Next;
           count=1;
           i=i+1;
        }
       // printf("%d\n",ptr2[0]->data);
       // printf("%d\n",ptr2[1]->data);
        
        for(i=interv_length-1;i>=1;i--)
        {
            //printf("e\n");
            if(extra>0)
            {
                count=1;
                temp2=ptr2[i];
                temp1=ptr2[i];
               // printf("f\n");
                while(temp2->Next!=NULL && count!=(interval+extra))
                {
                   // printf("g\n");
                    temp2=temp2->Next;
                    count=count+1;
                }
                extra=0;
                struct node*temp=temp1->prev;
                // printf("n\n");
                temp->Next=NULL;
               //  printf("0\n");
                temp2->Next=ptr2[i-1]; 
                  // printf("m\n");
                //  else
                //   temp2->Next=NULL;
                struct node* prevs=temp2->Next->prev;
               // printf("h\n");
                temp2->Next->prev=temp2;
              //  printf("j\n");
                if(prevs!=NULL)
                {
                    prevs->Next=temp1;
                }
                temp1->prev=prevs;
            }
            else{
                count=1;
                printf("g\n");
                temp2=ptr2[i];
                temp1=ptr2[i];
                while(count!=interval)
                {
                //    printf("i\n");
                    temp2=temp2->Next;
                    count=count+1;
                }
                struct node*temp=temp1->prev;
                temp->Next=NULL;
                
                temp2->Next=ptr2[i-1]; 
                // else
                //   temp2->Next=NULL;
                struct node* prevs=temp2->Next->prev;
               // printf("h\n");
                temp2->Next->prev=temp2;
              //  printf("j\n");
                if(prevs!=NULL)
                {
                    prevs->Next=temp1;
                }
                temp1->prev=prevs;
               // printf("K\n");
            }
        }
    }
   // printf("l\n");
    struct node*head=ptr2[interv_length-1];
   // printf("%d\n",head->data);
    print(head);
}

int sizes(struct node* root)
{
    struct node* ptr=root;
    int count=0;
    while(ptr!=NULL)
    {
        count=count+1;
        ptr=ptr->Next;
    }
    return count;
}

int main()
{
    struct node* Head1;
     struct node* second1;
      struct node* third1;
      struct node* forth1;
     struct node* fifth1;
     struct node* sixth1;
     struct node* seventh1;
     struct node* eight1;
     struct node* ninth1;

     Head1=(struct node*)malloc(sizeof(struct node));
     second1=(struct node*)malloc(sizeof(struct node));
    third1=(struct node*)malloc(sizeof(struct node));
     forth1=(struct node*)malloc(sizeof(struct node));
     fifth1=(struct node*)malloc(sizeof(struct node));
     sixth1=(struct node*)malloc(sizeof(struct node));
     seventh1=(struct node*)malloc(sizeof(struct node));
     eight1=(struct node*)malloc(sizeof(struct node));
     ninth1=(struct node*)malloc(sizeof(struct node));

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
    sixth1->Next=seventh1;
    sixth1->prev=fifth1;
    
    seventh1->data=7;
    seventh1->Next=eight1;
    seventh1->prev=sixth1;
    
    eight1->data=8;
    eight1->Next=ninth1;
    eight1->prev=seventh1;
    
    ninth1->data=13;
    ninth1->Next=NULL;
    ninth1->prev=eight1;
    
    int interval=3;
    int size=sizes(Head1);
    rotate(Head1,interval,size);
}