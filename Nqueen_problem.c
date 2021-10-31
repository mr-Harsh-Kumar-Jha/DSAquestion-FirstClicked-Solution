#include<stdio.h>
#define N 4
int IsSafe(int arr[N][N],int col,int row)
{
    int i,j;
    for (i = 0; i < row; i++){
        if(arr[col][i]==1)    //checking left part
            return 0;
    }
    for (i = col, j = row; j >= 0 && i < N; i++, j--)
    {
         if(arr[i][j]==1)    //checking upper left part
            return 0;
    }
    for (i = col, j = row; i >= 0 && j >= 0; i--, j--)
    {
        if(arr[i][j]==1)     //checking lower left part
            return 0;
    }
    return 1;
}

void print(int arr[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

int NQueen(int arr[N][N],int row)
{
   // printf("a\n");
      if(row==N)
      {
          return 1 ;
      }

      for(int i=0;i<N;i++)
      {
          if(IsSafe(arr,i,row)==1)
          {
              arr[i][row]=1;    //placing queen

             /* if(row==N)
              {
                  print(arr);
              }*/

             int note= NQueen(arr,row+1);//recursion

             if(note==1)
                 return 1;
             //printf("%d",arr[i][row]);

              arr[i][row]=0;  // backtracking
          }
         // printf("\n");
      }
      //printf("a\n");
      return 0;
}

int main()
{
   /* printf("N=");
    scanf("%d",&N);*/
     int arr[N][N]={ {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0} };


    if(NQueen(arr,0)==1)
    {
        print(arr);
    }
    else
      printf("soln not possible");

    return 1;
}
