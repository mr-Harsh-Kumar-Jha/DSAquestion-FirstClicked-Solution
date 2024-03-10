#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int print2largest(int arr[], int n) {
	    stack<int>s;
	    s.push(arr[0]);
	    for(int i=1;i<n;i++){
	        if(arr[i]>s.top()){
	            while(s.size()!=1){
	                int removedElem = s.top();
	                s.pop();
	                if(arr[i]==s.top()){
	                    s.push(removedElem);
	                    break;
	                }
	            }
	            if(arr[i]>s.top() && arr[i]!=s.top() && s.size()==1){
    	            int removedElement = s.top();
    	            s.pop();
    	            s.push(arr[i]);
    	            s.push(removedElement);
	            }else if(arr[i]!=s.top() && s.size()==1){
	                s.push(arr[i]);
	            }
	        }else if(arr[i]<s.top() && s.size()!=2){
	            s.push(arr[i]);
	        }
	    }
	    if(s.size()==2)
	        return s.top();
	    return -1;
	}
};