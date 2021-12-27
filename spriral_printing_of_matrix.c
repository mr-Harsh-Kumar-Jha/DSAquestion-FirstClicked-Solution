#include<stdio.h>

int row1=0;
int row2=4-1;
int col1=0;
int col2=4-1;
int i=0;
int j=0;
int previous;

int recurse(int arr[][4], int cases){
    // printf("b\n");
    if(j>col2){
        // printf("c\n");
       row1+=1;
       i=i+1;
       j=j-1;
      return 0;
     }
     if(j<col1){
        //  printf("d\n");
        row2-=1;
        i=i-1;
        j=j+1;
        return 0;
     }
     if(i>row2){
        //  printf("e\n");
      col2-=1;
      i=i-1;
      j=j-1;
      return 0;
     }
     if(i<row1){
        //   printf("f\n");
      col1+=1;
      i=i+1;
      j=j+1;
      return 0;
     }
    //   printf("g\n");
     printf("%d ",arr[i][j]);
     

     switch(cases)
     {
         case 0 :
            i=row1;
            j=j+1,
            recurse(arr , cases) ;
            break;
         case 1 :
             j=col2;
             i=i+1;
             recurse(arr, cases);
             break;
         case 2 :
              i=row2;
              j=j-1;
              recurse(arr, cases);
              break;
         case 3 :
              j=col1;
              i=i-1;
              recurse(arr, cases);
              break; 
         default:
              return 0;
     }
     return 1;
}

int main(){
 int cases;
 int arr[4][4]= {{1,   2,   3,   4},
                 {5,   6,   7,   8},
                 {9,  10,   11, 12},
                 {13, 14,   15, 16}};
 for(cases=0;cases<=(2*4)-2;cases++){
    // printf("%d\n",cases);
    int count=cases;
    count=count%4;
    recurse(arr, count);
    // printf("a\n");
 }
}