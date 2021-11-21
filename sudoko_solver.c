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

    int startRow = row - row % 3,
			startCol = col - col % 3;

    for (i = 0;i < 3; i++)    //checking sqrt9xsqrt9 box inside 9x9 container. 
    {
        for(j=0;j < 3; j++)
        {
            if(data==arr[i+startRow][j+startCol])    
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
    
      if(row==N-1 && col==N)
      {
        //  printf("\nm\n");
          return 1 ;
      }
      
      if(col>=N){
      //printf("b");
          row++;
          col=0;
      }
      
      
      while(col<N && arr[row][col]!=0)
      {
         // if(arr[row][col]!=0)
             col+=1;
      }
      
       if(col>=N){
      // printf("b");
          row+=1;
          col=0;
      }
      //  // printf("%d",col);

        // if (arr[row][col] > 0)
	       //     	return Sudoko_solver(arr, col+1, row);

       if(arr[row][col]==0){

      for(int j=1;j<=N;j++){
      // printf("c");
         if(IsSafe(arr,col,row,j)==1)
         {
            arr[row][col]=j;    
       
            /* if(row==N)
              {
                  print(arr);
              }*/
       
             /* int note= */ if(Sudoko_solver(arr,col+1,row)==1)//recursion
                                        return 1;
             // if(note==1){
                 //printf("L\n");
                
             // }
                    //printf("%d",arr[i][row]);
                    
                    arr[row][col]=0; // backtracking
         }
              
         
         // j=j+1;
    } 
  }
  else{
     if( Sudoko_solver(arr, col+1, row)==1)
     {
         return 1;
     }
  }
          
        //   printf("f\n"); 
         //  print(arr);
         //  printf("\n");
         // printf("k\n");
     return 0;  
}

int main()
{
   /* printf("N=");
    scanf("%d",&N);*/
   int grid[N][N] =  {{1, 0, 0,  0, 0, 7,  0, 9, 0}, 
                      {0, 3, 0,  0, 2, 0,  0, 0, 8}, 
                      {0, 0, 9,  6, 0, 0,  5, 0, 0}, 
                      {0, 0, 5,  3, 0, 0,  9, 0, 0}, 
                      {0, 1, 0,  0, 8, 0,  0, 0, 2}, 
                      {6, 0, 0,  0, 0, 4,  0, 0, 0}, 
                      {3, 0, 0,  0, 0, 0,  0, 1, 0}, 
                      {0, 4, 0,  0, 0, 0,  0, 0, 7}, 
                      {0, 0, 7,  0, 0, 0,  3, 0, 0}};
   
    int sudoko=Sudoko_solver(grid,0,0);
   // printf("d\n");
    if(sudoko==1)
    {
        printf("\n.............................................printing output.................................................\n");
        print(grid);
    }
    else{
     printf("soln does not exist");
    }

    return 1;
}
// 1 6 2 8 5 7 4 9 3 
// 5 3 4 1 2 9 6 7 8 
// 7 8 9 6 4 3 5 2 1 
// 4 7 5 3 1 2 9 8 6 
// 9 1 3 5 8 6 7 4 2 
// 6 2 8 7 9 4 1 3 5 
// 3 5 6 4 7 8 2 1 9 
// 2 4 1 9 3 5 8 6 7 
// 8 9 7 2 6 1 3 5 4 