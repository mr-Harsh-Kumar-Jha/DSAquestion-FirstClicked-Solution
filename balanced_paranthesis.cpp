#include<bits/stdc++.h>
using namespace std;

struct linked {
      char data;
      linked* next;
};

linked * top = NULL;

int isEmpty(){
   return top==NULL;
}

void stackcreate (int data ,linked* &head){
          linked * a = new  linked();

          if(head==NULL){

              a->data = data;
              head = a;
              top = head;
              a->next = NULL;
          }
          else{
             a->data = data;
             top->next = a;
             a->next = NULL;
             top = a;
          }
}

int  delet(linked*&head , char s){
    if(isEmpty()){
      cout<<"the paranthesis is not balanced due absence of opening paranthensis "<<endl;
      return 0;
    }
    else{
       linked* temp ;
      if(head==top){
         temp = NULL;
         if(s=='}' && top->data=='{'){
            free(top);
            top = temp;
            head=top;
         }
         else if(s==']' && top->data == '['){
             free(top);
            top = temp;
            head=top;
         }
         else if(s==')' && top->data == '('){
            free(top);
            top = temp;
            head=top;
         }
         else{
            cout<<"the paranthesis is not balanced due to dispositioning of closing paranthesis "<<endl;
            return 0;
         }
      }
      else{
          temp = head;
            while(temp->next != top){
                temp = temp->next;
           }
          if(s=='}' && top->data=='{'){
            free(top);
            top = temp;
         }
         else if(s==']' && top->data == '['){
             free(top);
            top = temp;
         }
         else if(s==')' && top->data == '('){
            free(top);
            top = temp;
         }
         else{
            cout<<"the paranthesis is not balanced due to dispositioning of closing paranthesis "<<endl;
            return 0;
         }
      }
    }
    return 1;

}

int main(){
       linked* head = NULL;
       string s;
       cin>>s;
       for(int i=0;i<s.length();i++){
             if(s[i]=='(' || s[i] == '[' || s[i]=='{'){
                stackcreate(s[i] , head);
             }
             else if(s[i]==')' || s[i] == ']' || s[i] == '}'){
                int res = delet(head,s[i]);
                if(res==0){
                    return 0;
                }
             }
       }
       if(head != NULL){
         cout<<"the paranthesis is not balanced because improper input of paranthesis is given"<<endl;
       }
       else{
         cout<<"the paranthesis is  balanced "<<endl;
       }
       return 0;
}