#include <bits/stdc++.h>
#define int long long
using namespace std;

struct phone{ // used for collision detection as we are using
   int data;
   phone *next;
};
array<phone *, 10> storage;

class telephone{
public:
   telephone(){
      storage.fill(NULL);
   }

   int hashFunction(int data){
      return data % 10;
   }

   phone *createNode(int data){
      phone *temp = new phone;
      temp->next = NULL;
      temp->data = data;
      return temp;
   }

   void insertElement(int data){
      int hash_id = hashFunction(data);
      phone *temp = createNode(data);
      phone *head = storage[hash_id];

      if (head == NULL){
         storage[hash_id] = temp;
      }
      else{
         while (head->next != NULL)
         {
            head = head->next;
         }
         head->next = temp;
      }
   }

   bool searchElement(int data){
      int hash_id = hashFunction(data);
      phone *head = storage[hash_id];

      if (head->data == data)
         return true;
      else{
         head = head->next;
         while (head != NULL){
            if (head->data == data) {
               return true;
            }
            head = head->next;
         }
         return false;
      }
   }

   void display(){
      for (int i = 0; i < 10; i++){
         phone *temp = storage[i];
         while (temp != NULL){
            cout << temp->data << ", ";
            temp = temp->next;
         }
         cout << endl;
      }
   }

   bool deleteElement(int data){
      int hash_id = hashFunction(data);
      phone *root = storage[hash_id];
      if (root == NULL)
         return false;

      if (root->data == data){
         phone *temp = root;
         root = root->next;
         delete (temp);
      }
      else{
         while (root != NULL){
            if (root->next->data == data){
               phone *temp = root->next;
               root->next = root->next->next;
               delete (temp);
               return true;
            }
            root = root->next;
         }
         return false;
      }
   }
};


signed main(){
    int ch;
    int data,search,del;
    telephone h;
    do{
        cout<<"\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \n\n OPTION: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter phone no. to be inserted : ";
                cin>>data;
                h.insertElement(data);
                break;
            case 2:
                h.display();
                break;
            case 3:
                cout<<"\nEnter the no to be searched : ";
                cin>>search;

                if (!h.searchElement(search))
                {
                    cout<<"No element found at key "<<endl;;
                    continue;
                }
                else{
                  cout<<"Phone No found at key "<<h.hashFunction(search)<<endl;
                }
                break;
            case 4:
                cout<<"\nEnter the phno. to be deleted : ";
                cin>>del;
                h.deleteElement(del);
                cout<<"Phno. Deleted"<<endl;
                break;
        }
    }while(ch!=5);

    return 0;
}