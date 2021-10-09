#include<stdio.h>

int main()
{
    int a,b,c;
    a=100;
    b=123;
    c=161;

    if(a>b && a>c)
    {
        if(b<c)
          printf("%d",c);
        else
        printf("%d",b);
    }
    else if(b>a && b>c){
        if(c<a)
          printf("%d",a);
        else  
          printf("%d",c);
    }
    else if(c>a && c>b)
    {
        if(a<b)
           printf("%d",b);
        else
           printf("%d",a);
    }
}