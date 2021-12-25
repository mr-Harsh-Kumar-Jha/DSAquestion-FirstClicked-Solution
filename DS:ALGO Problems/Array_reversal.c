/*Time complexity will be
      O(n)
*/

#include<stdio.h>

void reverse(int a[],int size,int d)//array reversal iteratively
{
    int b[size];
    int i=0;
    int j=d;
    while(j<size)
    {
        b[i]=a[j];
        i++;
        j++;
    }
    int c=0;
    while(i<size)
    {
        b[i]=a[c];
        i++;
        c++;
    }

    printf("Printing ur reversed array...................\n\n");
    for(i=0; i<size; i++)
    {
        printf("%d",b[i]);
    }
}

void call(int a[],int size,int d)
{
    if(size==NULL)
        return;
    else
    {
        reverse2(a,0,d-1);
        reverse2(a,d,size-1);
        reverse2(a,0,size-1);
    }

    printf("\n\nPrinting ur reversed array...................\n\n");
    for(int i=0; i<size; i++)
    {
        printf("%d",a[i]);
    }
}

int reverse2(int a[],int start,int end)//Method 2 (vvvimp)
{
    int temp;
    while(start<=end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    return a;
}

int main()
{
    int a[100];

    int d;

    printf("Enter the size of array.");
    int n;
    scanf("%d",&n);

    int size;
    size=n;

    printf("Enter the array.");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Enter the location from where u want to reverse the array.");
    scanf("%d",&d);

    reverse(a,size,d);

    call(a,size,d);
}
