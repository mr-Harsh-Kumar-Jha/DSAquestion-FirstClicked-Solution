
#include<stdio.h>
int j=0,k=0,l=0,m=0,n=0;

void print(int arr2[],int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        printf("%d",arr2[i]);
    }
}

int assign(int arr[],int lower_upper[],int upper_upper[],int mid_upper[],int N,int lower,int upper)
{
    printf("b");
    int i;
    while(i!=N)
    {
        printf("c");
        if(arr[i]<lower)
        {
            //    printf("%d",arr[i]);
            lower_upper[j]=arr[i];
            printf("%d",lower_upper[j]);
            j++;
            i++;
        }
        i++;
    }
    while(i!=N)
    {

        if(arr[i]>upper)
        {
            upper_upper[k]=arr[i];
            k++;
            i++;
        }
        i++
    }
    while(i!=N)
    {
        if(arr[i]>lower&&arr[i]<upper)
        {
            mid_upper[l]=arr[i];
            l++;
            i++;
        }
        i++
    }
    while(i!=N)
    {
        if(arr[i]==lower)
        {
            m=m+1;
        }
        else if(arr[i]==upper)
        {
            n=n+1;
        }
        i++;
    }

}

int partioning(int arr[],int N,int lower,int upper)
{
    int i=0;
    int lower_upper[50];
    int upper_upper[50];
    int mid_upper[50];
    int arr2[N];
    printf("a");
    assign(arr,N,lower_upper,upper_upper,mid_upper,lower,upper);
    printf("A\n");
    while(j!=0)
    {
        arr2[i]=lower_upper[j];
        j--  ;
        i++;
    }
    while(m!=0)
    {
        arr2[i]=lower;
        i++;
        m=m-1;
    }
    while(l!=0)
    {
        arr2[i]=mid_upper[l];
        i++;
        l--;
    }
    while(n!=0)
    {
        arr2[i]=upper;
        i++;
        n=n-1;
    }
    while(k!=0)
    {
        arr2[i]=upper_upper[k];
        i++;
        k--;
    }

    print(arr2,N);

}

int main()
{
    int arr[]= {87,15,20,5,10,9,1,2,53,76,16,18};
    int size=sizeof(arr)/sizeof(int) ;
    int lower=15;
    int upper=20;
    partioning(arr,size,lower,upper);
}

lower_upper[j]=arr[i];
printf("%d",lower_upper[j]);
j=j+1;
i=i+1;
}
i++;
}
while(i!=N)
{

    if(arr[i]>upper)
    {
        upper_upper[k]=arr[i];
        k++;
        i++;
    }
    i++
}
while(i!=N)
{
    if(arr[i]>lower&&arr[i]<upper)
    {
        mid_upper[l]=arr[i];
        l++;
        i++;
    }
    i++
}
while(i!=N)
{
    if(arr[i]==lower)
    {
        m=m+1;
    }
    else if(arr[i]==upper)
    {
        n=n+1;
    }
    i++;
}

}

int partioning(int arr[],int N,int lower,int upper)
{
    int i=0;
    int lower_upper[50];
    int upper_upper[50];
    int mid_upper[50];
    int arr2[N];
    printf("a");
    assign(arr,N,lower_upper,upper_upper,mid_upper,lower,upper);
    printf("A\n");
    while(j!=0)
    {
        arr2[i]=lower_upper[j];
        j--  ;
        i++;
    }
    while(m!=0)
    {
        arr2[i]=lower;
        i++;
        m=m-1;
    }
    while(l!=0)
    {
        arr2[i]=mid_upper[l];
        i++;
        l--;
    }
    while(n!=0)
    {
        arr2[i]=upper;
        i++;
        n=n-1;
    }
    while(k!=0)
    {
        arr2[i]=upper_upper[k];
        i++;
        k--;
    }

    print(arr2,N);

}

int main()
{
    int arr[]= {87,15,20,5,10,9,1,2,53,76,16,18};
    int size=sizeof(arr)/sizeof(int) ;
    int lower=15;
    int upper=20;
    partioning(arr,size,lower,upper);
}
