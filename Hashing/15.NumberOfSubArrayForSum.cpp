// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum)
    {
        //using map to store the prefix sum which has appeared already.
    	unordered_map<int, int> map;
    	
    	int curr_sum = 0;
    	int count=0; unordered_map<int,int>::iterator x;
    	
    	//iterating over the array elements.
        for (int i = 0; i < n; i++)
    	{
    	    //storing prefix sum which is sum of elements till current element.
    		curr_sum = curr_sum + arr[i];
    		
    		//checking if sum up to current element is equal to the given sum.
        	if (curr_sum == sum)
    		{
    		    //updating the counter.
    			count++;
    		}
    		//if map contains (curr_sum - sum) i.e. difference of current and 
    		//given sum, it means there is a subarray with sum of elements 
    		//equal to sum given.
    		x=map.find(curr_sum-sum);
    		if(x!=map.end())
    		//adding number of times (curr_sum - sum) has 
    		//appeared in map to the counter.
    		count+=x->second;
    		
    		//storing the prefix sum in map.
    		map[curr_sum]++;
    	}
    	//returning the count of subarrays.
    	return count;
    	
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution obj;
	    cout<<obj.subArraySum(arr, n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends