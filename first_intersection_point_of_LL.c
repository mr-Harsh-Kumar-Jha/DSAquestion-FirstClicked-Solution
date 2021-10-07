#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*Next;
};

struct Node* findintersection(struct Node*root1,struct Node*root2)
{
    while(root1->data!=root2->data)
    {
        if(root1->data > root2->data)
        {
            root2=root2->Next;
        }
        else
        {
            root1=root1->Next;
        }
    }
    return root1;
}

int main()
{
    struct Node *root1;
    struct Node *second1;
    struct Node *third1;
    struct Node *forth1;
    struct Node *fifth1;
    struct Node *sixth1;
    struct Node *seventh1;


    root1 = (struct Node*)malloc(sizeof(struct Node));
    second1 = (struct Node*)malloc(sizeof(struct Node));
    third1 = (struct Node*)malloc(sizeof(struct Node));
    forth1= (struct Node*)malloc(sizeof(struct Node));
    fifth1 = (struct Node*)malloc(sizeof(struct Node));
    sixth1 = (struct Node*)malloc(sizeof(struct Node));
    seventh1 = (struct Node*)malloc(sizeof(struct Node));

    root1->data=1;
    root1->Next=second1;
    second1->data=2;
    second1->Next=third1;
    third1->data=3;
    third1->Next=forth1;
    forth1->data=6;
    forth1->Next=fifth1;
    fifth1->data=10;
    fifth1->Next=sixth1;
    sixth1->data=11;
    sixth1->Next=seventh1;
    seventh1->data=12;
    seventh1->Next=NULL;





    struct Node *root2;
    struct Node *second2;
    struct Node *third2;
    struct Node *forth2;
    struct Node *fifth2;
    struct Node *sixth2;
    struct Node *seventh2;


    root1 = (struct Node*)malloc(sizeof(struct Node));
    second2 = (struct Node*)malloc(sizeof(struct Node));
    third2 = (struct Node*)malloc(sizeof(struct Node));
    forth2 = (struct Node*)malloc(sizeof(struct Node));
    fifth2 = (struct Node*)malloc(sizeof(struct Node));
    sixth2 = (struct Node*)malloc(sizeof(struct Node));
    seventh2 = (struct Node*)malloc(sizeof(struct Node));

    root2->data=4;
    root2->Next=second2;
    second2->data=5;
    second2->Next=third2;
    third2->data=7;
    third2->Next=forth2;
    forth2->data=8;
    forth2->Next=fifth2;
    fifth2->data=10;
    fifth2->Next=sixth2;
    sixth2->data=11;
    sixth2->Next=seventh2;
    seventh2->data=12;
    seventh2->Next=NULL;


      struct Node*ptr=findintersection(root1,root2) ;
      if(ptr==NULL)
      {
          printf("No possible intersection");
      }
      else{
        printf("%d",ptr->data);
      }


}
