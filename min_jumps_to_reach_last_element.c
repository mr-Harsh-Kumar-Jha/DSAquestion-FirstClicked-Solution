#include<stdio.h>
int min=2134658;
void jump(int arr[],int  length,int j,int count,int prev)
{
    if(prev>=length-1 /*&& count<min*/)
    {
        min=count+1;
      //  printf("%d",min);
        return;
    }
    else
    {
        if(arr[j]+j==j)
        {

            if(arr[j-1]==1|| arr[j-1]==0 && min==0)  //min  ko islye 0 ke barabar rakha hoo taki jab 0,0 do zero ek sath aaye to answer agar kisi path through end tak pauch chuka ho to next path ke through answer 0 nahi aana chayiea eg case(2,1,3,4,0,5,0,1,3,0,0,0)
            {
               // printf("%d",j);
                //printf("a\n");
                min=0;
            }
            return ;
        }
    }
   /* if(arr[j]/prev==0)
    {
        return;
    }*/
    for(int i=j+1;i<=prev;i++)
    {
       // count=count+1;
        jump(arr,length,i,count+1,arr[i]+i);
    }
}
int main() {
    int input[]={2,1,3,4,0,5,0,1,3,0,0,0};
    int size=sizeof(input)/sizeof(int);

    jump(input,size,0,0,input[0]);
    printf("%d",min);

    return 0;
}
