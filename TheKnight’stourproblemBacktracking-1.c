#include<stdio.h>
int count=0;

int isSafe(int arr[8][8], int xcord, int ycord){
 if(arr[xcord][ycord]==-1 && xcord<8 && ycord<8 && xcord>-1 && ycord>-1){
      return 1;
 }
 return 0;
}

int knighttour(int arr[8][8],int xcord, int ycord){
 // printf("b\n");
 if(count==64)
 {
  printf("b");
    return 1;
 }
 if(isSafe(arr,xcord,ycord)==1)
 {
    arr[xcord][ycord]=count;
    count=count+1;
    if(knighttour(arr,xcord+1,ycord+2)==1)
          return 1;

   else if(knighttour(arr,xcord+2,ycord+1)==1)
          return 1;

    else if(knighttour(arr,xcord-2,ycord+1)==1)
          return 1;

    else if(knighttour(arr,xcord+1,ycord-2)==1)
          return 1;

    else if(knighttour(arr,xcord-1,ycord-2)==1)
          return 1;

    else if(knighttour(arr,xcord-2,ycord-1)==1)
          return 1;

    else if(knighttour(arr,xcord+2,ycord-1)==1)
          return 1;

    else if(knighttour(arr,xcord-1,ycord+2)==1)
          return 1;

     arr[xcord][ycord]=-1;
     count=count-1;
     // printf("c\n");
     return 0;
 }
 return 0;
}

int main(){
    int arr[8][8];
    for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
      {
         arr[i][j]=-1;
      }
    }
    int xcord=0;
    int ycord=0;
    printf("c\n");
    int but=knighttour(arr,xcord,ycord);
    if(but==1)
    {
        for(int i=0;i<8;i++)
        {
          for(int j=0;j<8;j++)
          {
              printf("%d\t",arr[i][j]);
          }
          printf("\n\n");
        }

        printf("%d",count);
    }
    else{
      printf("sol'n doesnot exist");
    }
}