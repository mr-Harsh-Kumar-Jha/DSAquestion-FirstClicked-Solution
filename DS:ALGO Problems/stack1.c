#include<stdio.h>
#include<stdlib.h>
#define capacity 5

int stack[capacity];
int top=-1;



int main()
{
    int ch,item;

    while(1)
    {
        printf("1.push\n2.pop\n3.peek\n4.quit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1 :
            printf("Enter the no u want to push: ");
            scanf("%d",&item);
            push(item);

            break;
        case 2:
            item=pop(top);
            if(item==0)
            {
                printf("stack is underflow");
            }
            else
            {
                printf("your poped item is: %d",item);
            }
            break;
        case 3:
            printf("t");
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid  input\n\n");
        }

    }
}
    void push(int item)
    {
        if(isfull(top))
        {
            printf("stack over flown:");
        }
        else
        {
            top++;
            stack[top]=item;
            printf("your item is pushed: ");
        }

    }

    int isfull(int top)
    {
        if(top==(capacity-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isempty(int top)
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int pop(int top)
    {
        if(isempty(top))
        {
            printf("stack is underflow: ");
        }
        else
        {
            return stack[top--];
        }
    }



