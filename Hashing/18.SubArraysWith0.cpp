// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //using a map to store frequency of values obtained for prefix sum.
    	unordered_map<int, int> um;
    	int curr_sum = 0;
    	
    	//iterating over the array.
    	for (int i = 0; i < n; i++) {
    	    
    	    //calculating prefix sum by considering 0 as -1 and adding 1 if 
    	    //value of arr[i] is 1 or adding -1 if it is 0.
    		curr_sum += (arr[i] == 0) ? -1 : arr[i];
    		
    		//updating the value in map.
    		um[curr_sum]++;
    	}
    	long long int count = 0;
    	
    	//iterating over the map.
    	for (auto itr = um.begin(); itr != um.end(); itr++){
    	    
    	    //if value of any element in map is more than 1, then we 
    	    //update the count of subarrays.
    	    //count=(value*(value-1))/2 where value is value of key in map.
    		if (itr->second > 1)
    			count += ((itr->second * (itr->second - 1)) / 2);
    	}
    	
    	//adding frequency of sum 0 in the map to the final result.
    	if(um.find(0) != um.end())
    		count += um[0];
    		
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends