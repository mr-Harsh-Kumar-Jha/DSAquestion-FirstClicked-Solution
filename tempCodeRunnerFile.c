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