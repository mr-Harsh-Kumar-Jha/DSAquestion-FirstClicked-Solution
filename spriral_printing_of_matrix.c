#include<stdio.h>

int row1=0;
int row2=3-1;
int col1=0;
int col2=4-1;
int i=0;
int j=0;

int recurse(int arr[][4], int cases){
  
    if(j>col2){   // this is to control our terminating point when j exceeds its limit(i.e j ka limit here is 4) 
     
       row1+=1;
       i=i+1;
       j=j-1;
      return 0;
     }
     if(j<col1){   // this is to control our terminating point when j deficiate its limit(i.e j ka defecite is less than 0)
       
        row2-=1;
        i=i-1;
        j=j+1;
        return 0;
     }
     if(i>row2){   // this is to control our terminating point when i exceeds its limit(i.e i ka limit here is  3)
       
      col2-=1;
      i=i-1;
      j=j-1;
      return 0;
     }
     if(i<row1){  // this is to control our terminating point when i deficiate its limit(i.e i ka defecite is less than 0)
        
      col1+=1;
      i=i+1;
      j=j+1;
      return 0;
     }
    
     printf("%d ",arr[i][j]);
     

     switch(cases)
     {
         case 0 :     //  goes right hand side 
            i=row1;
            j=j+1,
            recurse(arr , cases) ;
            break;
         case 1 :    //  goes downward direction
             j=col2;
             i=i+1;
             recurse(arr, cases);
             break;
         case 2 :    //  goes left hand side
              i=row2;
              j=j-1;
              recurse(arr, cases);
              break;
         case 3 :    //  goes upward direction
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
 int arr[3][4]= {{1, 2, 3, 4},
                 {5, 6, 7, 8},
                 {9, 10, 11, 12}};
 for(cases=0;cases<=(2*3)-1;cases++){
    int count=cases;
    count=count%3; // here 3 is no_of_array.
    recurse(arr, count);
 }
}