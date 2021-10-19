#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* Next; 
};

struct node* Head8=NULL;

void sortmerge(int data)
{
   // printf("1\n");
    struct node* ptr2;
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->Next=NULL;
   // printf("h\n");
     if (Head8==NULL)
     {
     //   printf("k\n");
        Head8=ptr;
        Head8->Next=NULL;
     }
     else{
               
               ptr2=Head8;
              // print(Head8);
              // printf("%d\n",Head8->Next);
     
              // printf("i\n");
               while(ptr2->Next!=NULL)
               {
               //     printf("j\n");
                   ptr2=ptr2->Next;
               }
             //  printf("k\n");
               ptr2->Next=ptr;
     }
   //  printf("g\n");
     //print(Head8);
    // return Head8;
     

}

void merge(struct node* root1,struct node* root2,struct node* root3)
{
      //printf("b\n");
      //struct node* Head8=NULL;
      struct node* temp= root1;
      while(temp!=NULL || root2!=NULL || root3!=NULL)
      {
         //printf("\nc");
          if(temp!=NULL && root2!=NULL && root3!=NULL && temp->data < root2->data && temp->data < root3->data)
          {
              //printf("d");
               sortmerge(/*Head8*/temp->data);
               struct node* prev=temp;
               temp=temp->Next;
               free(prev);
          }
          else if(temp!=NULL && root2!=NULL && root3!=NULL && root2->data < temp->data && root2->data < root3->data )
          {
               //printf("e");
               sortmerge(/*Head8*/root2->data);
               struct node* prev=root2;
               root2=root2->Next;
               free(prev);
              // printf("f\n");
               
          }
          else if(temp!=NULL && root2!=NULL && root3!=NULL && root3->data < temp->data && root3->data < root2->data)
          {
              // printf("u");
               sortmerge(/*Head8*/root3->data);
               struct node* prev=root3;
               root3=root3->Next;
               free(prev);
          }
          else if(temp==NULL && root2!=NULL && root3!=NULL && root2->data < root3->data)
          {
               //printf("v");
               sortmerge(/*Head8*/root2->data);
               struct node* prev=root2;
               root2=root2->Next;
               free(prev);
              // printf("n");
          }
          else if(root2==NULL && temp!=NULL && root3!=NULL && temp->data < root3->data)
          {
                //printf("w");
               sortmerge(/*Head8*/ temp->data);
               struct node* prev=temp;
               temp=temp->Next;
               free(prev);
          }
          else if(root3==NULL && temp!=NULL && root2!=NULL && temp->data < root2->data)
          {
               //printf("x");
               sortmerge(/*Head8,*/temp->data);
               struct node* prev=temp;
               temp=temp->Next;
               free(prev);
          }
          else if(root3==NULL && root2!=NULL && temp!=NULL && temp->data > root2->data)
          {
              // printf("y");
               sortmerge(/*Head8,*/root2->data);
               struct node* prev=root2;
               root2=root2->Next;
               free(prev);
          }
          else if(root2==NULL && root3!=NULL && temp!=NULL && temp->data > root3->data)
          {
              // printf("z");
               sortmerge(/*Head8,*/root3->data);
               struct node* prev=root3;
               root3=root3->Next;
               free(prev);
          }
          else if(temp==NULL && root3!=NULL && root2!=NULL && root2->data > root3->data)
          {
              // printf("p");
               sortmerge(/*Head8,*/root3->data);
               struct node* prev=root3;
               root3=root3->Next;
               free(prev);
          }
          else if(temp==NULL && root2==NULL && root3!=NULL)
          {
              // printf("q");
               while(root3!=NULL){
                    sortmerge(/*Head8,*/root3->data);
                    root3=root3->Next;
               }
              
          }
          else if(temp==NULL && root3==NULL && root2!=NULL)
          {
              // printf("r\n");
               while(root2!=NULL){
                    sortmerge(/*Head8,*/root2->data);
                    root2=root2->Next;
               }
          }
          else if(root2==NULL && root3==NULL && temp!=NULL)
          {
              // printf("s");
              while(temp!=NULL){
                    sortmerge(/*Head8,*/temp->data);
                    temp=temp->Next;
               }
          }
         // print(Head8);
          //printf("\n");
         // printf("%d\n",root3->data);
          
      }
     /* return Head8;*/
}

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


int main()
{
     struct node* Head1;
     struct node* second1;
      struct node* third1;
      struct node* forth1;
     struct node* fifth1;
     struct node* sixth1;

     Head1=(struct node*)malloc(sizeof(struct node));
     second1=(struct node*)malloc(sizeof(struct node));
    third1=(struct node*)malloc(sizeof(struct node));
     forth1=(struct node*)malloc(sizeof(struct node));
     fifth1=(struct node*)malloc(sizeof(struct node));
        sixth1=(struct node*)malloc(sizeof(struct node));

    Head1->data=1;
    Head1->Next=second1;

    second1->data=3;
    second1->Next=third1;
 
    third1->data=5;
    third1->Next=forth1;

    forth1->data=7;
    forth1->Next=fifth1;

    fifth1->data=9;
    fifth1->Next=sixth1;
    
      sixth1->data=25;
    sixth1->Next=NULL;


    struct node* Head2;
     struct node* second2;
      struct node* third2;
      struct node* forth2;
     struct node* fifth2;
     struct node* sixth2;

     Head2=(struct node*)malloc(sizeof(struct node));
     second2=(struct node*)malloc(sizeof(struct node));
    third2=(struct node*)malloc(sizeof(struct node));
     forth2=(struct node*)malloc(sizeof(struct node));
     fifth2=(struct node*)malloc(sizeof(struct node));
     sixth2=(struct node*)malloc(sizeof(struct node));
     sixth2->data=22;
    sixth2->Next=NULL;

    Head2->data=2;
    Head2->Next=second2;

    second2->data=4;
    second2->Next=third2;
 
    third2->data=6;
    third2->Next=forth2;

    forth2->data=8;
    forth2->Next=fifth2;

    fifth2->data=10;
    fifth2->Next=sixth2;

    sixth2->data=22;
    sixth2->Next=NULL;

    struct node* Head3;
     struct node* second3;
      struct node* third3;
      struct node* forth3;
     struct node* fifth3;
    // struct node* sixth3;

     Head3=(struct node*)malloc(sizeof(struct node));
     second3=(struct node*)malloc(sizeof(struct node));
    third3=(struct node*)malloc(sizeof(struct node));
     forth3=(struct node*)malloc(sizeof(struct node));
     fifth3=(struct node*)malloc(sizeof(struct node));
    // sixth3=(struct node*)malloc(sizeof(struct node));

    Head3->data=11;
    Head3->Next=second3;

    second3->data=13;
    second3->Next=third3;
 
    third3->data=15;
    third3->Next=forth3;

    forth3->data=18;
    forth3->Next=fifth3;

    fifth3->data=20;
    fifth3->Next=NULL;

   /* sixth3->data=21;
    sixth3->Next=NULL;*/

    
    //printf("a\n");
     merge(Head1,Head2,Head3);
     print(Head8);
}






/*   METHOD 2...................................

#include <bits/stdc++.h>
using namespace std;
 
// A Linked List node
struct Node {
    int data;
    Node* next;
};
 
// Function to print nodes in
 //  a given linked list 
void printList(Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
// The main function that
// takes an array of lists
// arr[0..last] and generates
// the sorted output
Node* mergeKLists(Node* arr[], int last)
{
 
    // Traverse form second list to last
    for (int i = 1; i <= last; i++) {
        while (true) {
            // head of both the lists,
            // 0 and ith list.
            Node *head_0 = arr[0], *head_i = arr[i];
 
            // Break if list ended
            if (head_i == NULL)
                break;
 
            // Smaller than first element
            if (head_0->data >= head_i->data) {
                arr[i] = head_i->next;
                head_i->next = head_0;
                arr[0] = head_i;
            }
            else
                // Traverse the first list
                while (head_0->next != NULL) {
                    // Smaller than next element
                    if (head_0->next->data
                        >= head_i->data) {
                        arr[i] = head_i->next;
                        head_i->next = head_0->next;
                        head_0->next = head_i;
                        break;
                    }
                    // go to next node
                    head_0 = head_0->next;
 
                    // if last node
                    if (head_0->next == NULL) {
                        arr[i] = head_i->next;
                        head_i->next = NULL;
                        head_0->next = head_i;
                        head_0->next->next = NULL;
                        break;
                    }
                }
        }
    }
 
    return arr[0];
}
 
// Utility function to create a new node.
Node* newNode(int data)
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 
// Driver program to test
// above functions
int main()
{
    // Number of linked lists
    int k = 3;
 
    // Number of elements in each list
    int n = 4;
 
    // an array of pointers storing the
    // head nodes of the linked lists
    Node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);
 
    printList(head);
 
    return 0;
}
*/