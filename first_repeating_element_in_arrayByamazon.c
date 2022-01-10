  //picking up first repeated no and printing up:

/* input
   1,2,3,1,2;
   
   output
   your first repeated no is 1;
*/ 

#include<stdio.h>
int main()
{
	int arr[50],n,i,j;
	
	printf("Enter the size of array : ");
	scanf("%d",&n);
	
	printf("Enter your array : ");
	
	for (i=0;i<n;i++)
	{
		printf("arr[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	i=1;
	j=0;
	
	while(j<n-1)
	{
		if(arr[j]!=arr[i])
		{
			i++;
		} 
		
		if(arr[j]==arr[i])
		{
		    printf("Your first rpeated no is : %d",arr[j]);
			break; 	
		}
		
		if(i>n-2)
		{
			i=1+(j+1);
			j++;
		}
	}       
}  
