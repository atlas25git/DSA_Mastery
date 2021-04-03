// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
        void kthLargest(int arr[], int N, int k)
    {
    	priority_queue<int,vector<int>,greater<int>> pq; // making Minheap
    	
    	for(int i=0;i<N;i++)
    	{
    	    if(pq.size() < k) 
    			pq.push(arr[i]);
    		else // if size becomes equal to k
    		{
    			if(arr[i] > pq.top()) // if top element is smaller than arr[i]
    			{
    				pq.pop();
    				pq.push(arr[i]);
    			}
    		}
    		
    		if(pq.size()<k)
    			cout<<-1<<" ";
    		else
    			cout<<pq.top()<<" "; // print the current top element
    	}
    }
};
// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k, n;
		cin>>k>>n;
	    
	    int arr[n];
	    for(int i = 0; i<n ; ++i)
	        cin>>arr[i];
        Solution ob;
	    ob.kthLargest(arr, n, k);
	    cout<<endl;
	    
	    
	}
	return 0;
}
  // } Driver Code Ends