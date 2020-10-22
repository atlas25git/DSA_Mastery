//https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int ms[n];
	    for(int i=0;i<n;i++)
	    {
	        ms[i]=arr[i];
	        for(int j=0;j<i;j++)
	            if(arr[j]<arr[i])
	                ms[i]=max(ms[i],arr[i]+ms[j]);
	    }
	    int res=ms[0];
	    for(int i=1;i<n;i++)res=max(res,ms[i]);
	    return res;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends