 #include<stdio.h>

int main()
{
	int arr[54],n;
	int i,days=0,store;

	printf("Enter the no of day : ");
	scanf("%d",&n);

	printf("Enter your no of visitors for each day: \n");
	for(i=0;i<n;i++)
	{
		printf("day[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}

/*	if(n==1)
	{
		printf("%d",days);
	}*/

	i=0;
	if(arr[0]>arr[1])
    {
    	days++;
    	store=i;
	}
    while(i<n)
    {
		if(arr[i+1]>arr[i] && arr[i+1]>arr[store] && arr[i+1]>arr[i+2] && i!=n-1)  //comparing all relatedaspects like second term is greater or not 2.if greater compare it with first highest 3.is greater then compare it with element after it if greater the days will increase nade hinghest value will be updated.
		{
			//printf("hi %d\n",arr[i+1]);
			days++;
		   	store=i+1;
		}
		i++;
	}
   	if(i==n-1 && arr[n-1]>arr[n-2] && arr[n-1]>arr[store])
	{
	    days++;
    }

	printf("\n%d",days);
}
