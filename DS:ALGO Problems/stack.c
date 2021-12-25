#include<stdio.h>
#include<stdlib.h>

struct insertion
{
    int data;
    struct insertion *next;
} ;

void link(struct insertion* ptr,int data)
{
    struct insertion* p=(struct insertion*)malloc(sizeof(struct insertion));
    p->next=ptr;
    p->data=data;

    while(ptr!=NULL)
    {
        printf("element : %d\n",p->data);
        p=p->next;
    }

}
int main()
{
    struct insertion *head;
    struct insertion *second;
    struct insertion *third;
    struct insertion *fourth;

    head=(struct insertion*)malloc(sizeof(struct insertion));
    second=(struct insertion*)malloc(sizeof(struct insertion));
    third=(struct insertion*)malloc(sizeof(struct insertion));
    fourth=(struct insertion*)malloc(sizeof(struct insertion));

    head->data=4;
    head->next=second;
    second->data=5;
    second->next=third;
    third->data=6;
    third->next=fourth;
    fourth->data=7;
    fourth->next=NULL;

    link(head,30);
}
