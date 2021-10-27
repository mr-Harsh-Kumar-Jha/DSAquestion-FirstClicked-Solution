#include<stdio.h>

int isSafe(int arr[4][4],int   size,int i,int j)
{
       if(i<size && j<size && arr[i][j]==1)
       {
        //   printf("k\n");
          return 1;  
       }

       return 0;
}

int maiz(int arr[4][4],int size,int i,int j,int arr1[4][4])
{
    // printf("a\n");
      if(i==size-1 && j==size-1 && arr[i][j]==1 )
      {
          arr1[i][j]=1;
        //   printf("b\n");
             return 1;
      }
      
      if(isSafe(arr,size,i,j)==1)
      {
            // printf("c\n");
             arr[i][j]=0;
             arr1[i][j]=1;     
             if(maiz(arr,size,i+1,j,arr1)==1)
                  return 1;

             if(maiz(arr,size,i,j+1,arr1)==1)
                   return 1;

             if( maiz(arr,size,i-1,j,arr1)==1)
                   return 1;

             if( maiz(arr,size,i,j-1,arr1)==1)
                   return 1; 
                   
             arr1[i][j]=0;
             return 0;            
      }
        // printf("d\n");
       //return 0;
     
      
}

int main()
{
    int path[4][4]={{1, 0, 0, 0},
                  {1, 1, 0, 1}, 
                  {1, 1, 0, 0},
                  {0, 1, 1, 1}};

    int size=sizeof(path)/sizeof(int);  
    int arr1[4][4]={{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};

    int win=maiz(path,4,0,0,arr1);
    if(win==0)
    {
       printf("rat is trapped!....");
    }
    else if(win==1){
       for(int i=0;i<4;i++)
       {
          for(int j=0;j<4;j++)
          {
             printf("%d",arr1[i][j]);
          }
          printf("\n");
       }
    }
}