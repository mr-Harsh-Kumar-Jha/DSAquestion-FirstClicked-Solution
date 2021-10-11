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

int main()
{
    //constructing the root node.
    struct node* p=tree(35);
    struct node* p1=tree(45);
    struct node* p2=tree(55);
    struct node* p3=tree(3);
    struct node* p4=tree(5);

    //linking the root node with right and left children.
    p->L=p1;
    p->R=p2;
    p1->L=p3;
    p1->R=p4;

    inorder(p);
    printf("\n");
    preorder(p);
    printf("\n");
    postorder(p)

}
