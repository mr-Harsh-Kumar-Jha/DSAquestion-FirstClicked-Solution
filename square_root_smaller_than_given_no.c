#include<stdio.h>
#include<math.h>

void searching(int sample[],int N,int size)
{
    int count=0;
    for(int i=0;i<(int) sqrt(N);i++)
    {
        count=count+1;
    }
    printf("%d",count);
}

int main()
{
    int sample[]={1,4,9,16,25,36,49,64,81,100};
    int size=sizeof(sample)/sizeof(int);
    int N=23;
    searching(sample,N,size);
}
