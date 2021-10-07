#include<stdio.h>
#include<stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct CircularQueue* p)
{
    if(((p->r+1)%p->size)==p->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue* p)
{
    if(p->f==p->r)
    {
        return 1;
    }
    return 0;

}
int dequeue(struct CircularQueue* p)
{
    if(isEmpty(p))
    {
        return -1;
    }
    else
    {
        p->f=(p->f+1)%p->size;
        int a=p->arr[p->f];
        return a;
    }
}

void enque(struct CircularQueue* p,int a)
{
    if(isFull(p))
    {
        printf("\nQueue is overflown.");
    }
    else
    {
        p->r=(p->r+1)%p->size;
        p->arr[p->r]=a;
        printf("Element %d Enqueued .",a);
    }
}

int main()
{
    struct CircularQueue q;
    int n,b,c,a;

    printf("Enter the size of the Area: ");
    scanf("%d",&n);
    q.size=n;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    while(1)
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        scanf("%d",&b);

        switch(b)
        {
        case 1:
            printf("\nEnter the digit u want to enqueue:");
            scanf("%d",&c);
            enque(&q,c);
            break;
        case 2:
             a=dequeue(&q);
            if(a==-1)
            {
                printf("\nQueue is empty.");
            }
            else{
                    printf("\n\nelement %d dequeued.",a);
            }
            break;
        case 3:
            exit(1);
        default:
            printf("Wrong input.");
        }
    }
}
