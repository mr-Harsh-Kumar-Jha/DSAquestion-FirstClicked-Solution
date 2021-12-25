#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* R;
    struct node* L;
};

struct node* tree(int a)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));//creating a node pointer & allocating memory in heap.
    p->data=a;//setting a data.
    p->L=NULL;//setting the left and right child to NULL.
    p->R=NULL;//setting the left and right child to NULL.

    printf("element pushing\n");
    return p;//finally returning the created node.
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->L);
        printf("%d ",root->data);
        inorder(root->R);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->L);
        preorder(root->R);
    }
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->L);
        postorder(root->R);
        printf("%d ",root->data);
    }
}

void insert(struct node* p)
{
    struct node* root;
    struct node* parent=root;

    if(root==NULL)
    {
        root=p;
    }
    else
    {
        struct node* current;
        current=root;

        while(current!=NULL)
        {
            parent=current;

            if(p->data>current->data)
            {
                current=current->R;
            }
            else{
                current=current->L;
            }
        }
        if(p->data > parent->data)
        {
            parent->R=p;
        }
        else{
            parent->L=p;
        }
   }
}

int main()
{
    //constructing the root node.
    int a,ch;
    struct node* root;

     while(1)
    {
        printf("1.Insert\n2.Inorder traversal\n3.Postorder Traversal\n4.quit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1 :
           printf("Enter the no u want to insert.");
           scanf("%d",&a);
           struct node* t=tree(a);
           insert(t);
           printf("\n");
           break;
        case 2:
            inorder(t);
            printf("\n");
            break;
        case 3:
            postorder(t);
            printf("\n");
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid  input\n\n");
        }

    }
    //preorder(p);//

}
