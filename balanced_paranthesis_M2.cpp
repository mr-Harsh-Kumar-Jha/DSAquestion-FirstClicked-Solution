#include <bits/stdc++.h>
using namespace std;
string str;
int top = -1;

bool isEmpty(){
   if (top == -1)
      return 1;
   else
      return 0;
}

bool isFull(){
   if (top == str.length() - 1)
      return 1;
   else
      return 0;
}

void display(){
   if (isEmpty() == 1)
      cout << "Stack is empty" << endl;
   else
   {
      for (int i = 0; i <= top; i++)
      {
         cout << " " << str[i];
      }
   }
}

void push(char ch){
   if (!isFull())
   {
      top++;
      str[top] = ch;
   }
}

char pop()
{
   if (!isEmpty())
   {
      char ch = str[top];
      top--;
      return ch;
   }
   else
   {
      return '\0';
   }
}

void checkParenthesis(){
   cout << "Enter Expression: " << endl;
   cin >> str;
   char ch;
   bool flag = 0;
   for (int i = 0; i < str.length(); i++)
   {
      if (str[i] == '(' || str[i] == '[' || str[i] == '{')
         push(str[i]);
      if (str[i] == ')' || str[i] == ']' || str[i] == '}')
      {
         ch = pop();
         if ((str[i] == ')' && ch != '(') || (str[i] == ']' && ch != '[') || (str[i] == '}' && ch != '{'))
         {
            cout << "Not parenthesized At " << i << endl;
            flag = 1;
            break;
         }
      }
   }
   if (isEmpty() == 1 && flag == 0)
      cout << "Expresseion is Parenthesized." << endl;
}

int main(){

   int choice;
   checkParenthesis();
   return 0;
}