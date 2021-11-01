#include<stdio.h>
#define N 9
int IsSafe(int arr[N][N],int col,int row,int data)
{
    int i,j;
    if(col==N||row==N)
        return 0;
        
    
    for (i = 0; i < N; i++)    //checking Right part
    {
        if(data==arr[row][i])    
            return 0;
    }
    for (i = 0;i < N; i++)    //checking Down part
    {
         if(data==arr[i][col])    
            return 0;
    }
    for (i = (3*(row/3));i < 3*((row/3)+1); i++)    //checking sqrt9xsqrt9 box inside 9x9 container. 
    {
        for(j=3*(col/3);j < 3*((col/3)+1); j++)
        {
            if(data==arr[i][j]==1)    
               return 0;
        }
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
            printf(" ");
        }
        printf("\n");
    }
}

int Sudoko_solver(int arr[N][N],int col,int row)
{
   // printf("a");
    
      if(row>=N-1 && col==N)
      {
        //  printf("\nm\n");
          return 1 ;
      }
      
      if(col>=N){
      //printf("b");
          row+=1;
          col=0;
      }
      
      
      while(col<=N && arr[row][col]!=0)
      {
         if(arr[row][col]!=0)
             col+=1;
      }
      
       if(col>=N){
      // printf("b");
          row+=1;
          col=0;
      }
       //printf("%d",col);
       if(arr[row][col]==0){

      for(int j=1;j<=N;){
      // printf("c");
         if(IsSafe(arr,col,row,j)==1)
         {
            arr[row][col]=j;    
       
            /* if(row==N)
              {
                  print(arr);
              }*/
       
             int note= Sudoko_solver(arr,col+1,row);//recursion

             if(note==1){
                 //printf("L\n");
                return 1;
             }
                    //printf("%d",arr[i][row]);

             arr[row][col]=0;  // backtracking
         }
         j=j+1;
    } 
       }
       else{
          if( Sudoko_solver(arr, col+1, row)==1)
          {
              return 1;
          }
       }
          
        //   printf("f\n");
        //   print(arr);
        //   printf("\n");
    //      printf("k\n");
     return 0;
      
     
}

int main()
{
   /* printf("N=");
    scanf("%d",&N);*/
   int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
   
    int sudoko=Sudoko_solver(grid,0,0);
   // printf("d\n");
    if(sudoko==1)
    {
        printf("\n.............................................printing output.................................................\n");
        print(grid);
    }

    return 1;
}
        //   3 1 6 5 7 8 4 9 2 
        //   5 2 9 1 3 4 7 6 8 
        //   4 8 7 6 2 9 5 3 1 
        //   2 6 3 4 1 5 9 8 7 
        //   9 7 4 8 6 3 1 2 5 
        //   8 5 1 7 9 2 6 4 3 
        //   1 3 8 9 4 7 2 5 6 
        //   6 9 2 3 5 1 8 7 4 
        //   7 4 5 2 8 6 3 1 9 