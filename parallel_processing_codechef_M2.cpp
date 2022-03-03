//Parallel Processing Problem Code: PLPROCESS

/* There are N tasks waiting in line to be executed. The execution time for the ith task is Ai seconds.

Chef has two processors to execute these N tasks. Both these processors work simultaneously. Each processor executes the assigned tasks one by one.

Chef assigns a prefix of these tasks to the first processor and the remaining tasks to the second processor.

For example, if there are 3 tasks, Chef can do one of the following:

Assign no task to the first processor. This means, the second processor will execute tasks 1,2 and 3.
Assign task 1 to the first processor. This means, the second processor will execute tasks 2 and 3.
Assign tasks 1 and 2 to the first processor. This means, the second processor will execute task 3.
Assign tasks 1,2 and 3 to the first processor. Thus, second processor would execute no tasks.
Find the minimum time in which all the tasks can be executed. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
     int *prefix;
	    int *suffix;
	while(t--){
	    int N;
	    int min=INT_MAX;
       int sum2=0;
	    int sum1=0;
	    int count=0;
       prefix=new int[N];
       suffix=new int[N];

	    cin>>N;
	   int arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        sum2=sum2+arr[i];
	    }
	    if(N>1){
	    for(int i=0;i<N;i++){
          if(i==0)
            prefix[i]=arr[i];
         else
	        prefix[i]=arr[i]+prefix[i-1];
	    }

	    for(int i=N-1;i>=0;i--){
	        sum1=sum1+arr[i];
	        suffix[i]=sum1;
	    }

	    for(int i=0;i<N-1;i++){
	        if( i+1<N && suffix[i+1]>prefix[i]){
	            if(suffix[i+1] < min){
	                min=suffix[i+1];
	            }
	        }
	        else{
	            if(i+1<N && prefix[i] < min){
	                min=prefix[i];
	            }
	        }

	    }
	    }
	    else{
	        min=sum2;
	    }
	    cout<<min<<endl;

	}
	return 0;
}
