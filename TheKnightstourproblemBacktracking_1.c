//this solution takes time to give output but the thing is that output is priented
#include<stdio.h>
#define N 6

int isSafe(int arr[N][N], int xcord, int ycord){
 if(xcord<N && ycord<N && xcord>=0 && ycord>=0 && arr[xcord][ycord]==-1){
      return 1;
 }
 return 0;
}

int knighttour(int arr[N][N],int xcord, int ycord ,int count){
//  printf("b\n");
 if(count==N*N)
 {
    return 1;
 }
 if(isSafe(arr,xcord,ycord))
 {
    arr[xcord][ycord]=count;
    count=count+1;
    if(knighttour(arr,xcord+2,ycord+1,count)){
       
          return 1;
     }
   else if(knighttour(arr,xcord+1,ycord+2,count)){
          
          return 1;
    }
   else if(knighttour(arr,xcord-1,ycord+2,count)){
          return 1;
    }
   else if(knighttour(arr,xcord-2,ycord+1,count)){
          return 1;
    }
    else if(knighttour(arr,xcord-2,ycord-1,count)){
          return 1;
    }
   else if(knighttour(arr,xcord-1,ycord-2,count)){
          return 1;
   }
   else if(knighttour(arr,xcord+1,ycord+2,count)){
          return 1;
   }
   else if(knighttour(arr,xcord+2,ycord-1,count)){
          return 1;
   }
   else{
    //   printf("%d\n",arr[xcord][ycord]);
     arr[xcord][ycord]=-1;
    //  printf("%d",arr[xcord][ycord]);
     count=count-1;
    //   printf("%d",count);
   }
 }
   return 0;
}

int main(){
    int arr[N][N];
    for(int i=0;i<7;i++)
    {
      for(int j=0;j<7;j++)
      {
         arr[i][j]=-1;
      }
    }
    int xcord=0;
    int ycord=0;
    int count=0;

    // printf("c\n");
    int but=knighttour(arr,xcord,ycord,count);
    if(but==1)
    {
        for(int i=0;i<N;i++)
        {
          for(int j=0;j<N;j++)
          {
              printf("%d\t",arr[i][j]);
          }
          printf("\n");
        }

        printf("%d",count);
    }
    else
    {
      printf("sol'n doesnot exist");
    }
}