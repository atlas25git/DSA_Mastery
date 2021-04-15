// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    {
    	//Initialising index of first minimum and first maximum element. 
    	int max_idx = n - 1, min_idx = 0; 
    
    	//Storing maximum element of array. 
    	int max_elem = arr[n - 1] +1; 
    
    	for (int i = 0; i < n; i++) { 
    		//At even index, we have to put maximum elements in decreasing order. 
    		if (i % 2 == 0) { 
    			arr[i] += (arr[max_idx] % max_elem) * max_elem;
    			//Updating maximum index.
    			max_idx--; 
    		} 
    
    		//At odd index, we have to put minimum elements in increasing order. 
    		else { 
    			arr[i] += (arr[min_idx] % max_elem) * max_elem;
    			//Updating minimum index.
    			min_idx++; 
    		} 
    	} 
    
    	//Dividing array elements by maximum element to get the result. 
    	for (int i = 0; i < n; i++) 
    		arr[i] = arr[i] / max_elem; 
    }
};

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends