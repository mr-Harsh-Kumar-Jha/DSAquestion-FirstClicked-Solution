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

struct node* search(struct node* root,int data)
{
    if(root==NULL)
        return NULL;
    if(data==root->data)
        return root;
    else if(root->data>data)
        return search(root->L,data);
    else
        return search(root->R,data);
}

struct node* searchitr(struct node* root,int data)
{
    while(root!=NULL)
    {
        if(data==root->data)
            return root;
        else if(root->data>data)
             root=root->L;
        else
            root=root->R;
    }
    return NULL;
}

int main()
{
    //constructing the root node.
    struct node* p=tree(54);
    struct node* p1=tree(45);
    struct node* p2=tree(55);
    struct node* p3=tree(3);
    struct node* p4=tree(5);

    //linking the root node with right and left children.
    p->L=p1;
    p->R=p2;
    p1->L=p3;
    p3->R=p4;

    inorder(p);
    printf("\n");

    preorder(p);
    printf("\n");

    postorder(p);
    printf("\n");

    int data;
    printf("Enter the no u want to search in BST: ");
    scanf("%d",&data);
    struct node* q=search(p,data);//search recursively
    if(q==NULL)
    {
        printf("Recursively : NO element found.\n\n");
    }
    else
    {
        printf("Recursively : Yes,Element is present.\n\n");
    }

    struct node* z=searchitr(p,data);//search iteratively
    if(q==NULL)
    {
        printf("Iteratively : NO element found.\n\n\n");
    }
    else
    {
        printf("Iteratively : Yes,Element is present.\n\n\n");
    }
}
