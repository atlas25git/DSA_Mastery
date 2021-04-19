// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C

int searchInSorted(int arr[], int n, int k) 
{ 
    // store left index in l with 0 and right in r with n-1
    int l = 0, r = n-1;
    // calculate mid
    int m = l + (r-l) / 2;

    // binary search to find the element in sorted array
	while (l <= r) { 
	    // calculate mid on each iteration
		m = l + (r - l) / 2; 

		// Check if x is present at mid 
		if (arr[m] == k) 
			return 1; 

		// If x greater, ignore left half 
		if (arr[m] < k) 
			l = m + 1; 

		// If x is smaller, ignore right half 
		else
			r = m - 1; 
	} 
	
	// if we reach here, then element was not present 
	return -1; 
} 

// { Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 
  // } Driver Code Ends