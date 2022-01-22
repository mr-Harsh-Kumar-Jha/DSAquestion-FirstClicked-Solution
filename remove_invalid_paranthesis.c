#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int min=INT_MAX;

struct stack{
  int count;
  int top;
  int open;
  char* arr;
};

struct stack* make_stack(int count){
   struct stack* Q=(struct stack*)malloc(sizeof(struct stack));
   if(!Q){
      printf("Error!");
      return NULL;
   }
   Q->count=count;
   Q->top=-1;
   Q->open=-1;
   Q->arr=(char*)malloc(count*sizeof(char));
   return Q;
}

void push(struct stack* Q,char data){
   if(Q->top==Q->count){
      printf("stack full\n");
      return ;
   }
  Q->top+=1;
  Q->arr[Q->top]=data;
  return ;
}

void pop(struct stack* Q){
   if(Q->top==-1){
      printf("stack empty\n");
      return;
   }
   Q->top-=1;
   return ;
}

void print(struct stack*Q){
   for(int i=0;i<=Q->top;i++)
     printf("%c ",Q->arr[i]);

     printf("\n");
}

void find_invalid(char arr[],struct stack* Q,int size,int i,int count){
   // printf("2.hi ");
   // printf("%d\n",count);
     if(i==size-1 && count==0||i==size && count==0){
      //   printf("\t4.hi");
        if(size-Q->top-1 <= min){

           min= size - Q->top -1;
           printf("%d\n",min);
           print(Q);
           return;
        }
     }
     else if(i==size && count>0){
      //   printf("\t 3.hi \t");
        return;
     }
  for(;i<size+1;i++) {
   //  printf("\t1.hi ");

     if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
      //   printf("bro=%c\n",arr[i]);
        push(Q,arr[i]);
        count+=1;
        find_invalid(arr,Q,size,i+1,count);
         if(arr[i]=='(' || Q->arr[Q->top]=='{' || Q->arr[Q->top]=='['){
            pop(Q);
            count=count-1;
         }
        else
             pop(Q);
     }
     else if(arr[i]==')' && count!=0 || arr[i]=='}' && count!=0 || arr[i]==']' && count!=0){
      //   printf("%c\n",arr[i]);
        push(Q,arr[i]);
        count-=1;
        find_invalid(arr,Q,size,i+1,count);
         if(arr[i]=='(' || Q->arr[Q->top]=='{' || Q->arr[Q->top]=='['){
             pop(Q);
             count=count-1;
         }
         else{
             count=count+1;
              pop(Q);
         }
     }
     else if(arr[i]>='a' && arr[i]<='z'){
         push(Q,arr[i]);
        find_invalid(arr,Q,size,i+1,count);
           pop(Q);
     }

  }
  return;
}

int main(){
   char arr[]="(a)()z)()";
   int count=0;
   int i=0;

   int size=strlen(arr);
   struct stack* Q=make_stack(size);
   printf("harsh\n");
   find_invalid(arr,Q,size,i,count);

}