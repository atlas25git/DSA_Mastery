// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to find the minimum element in sorted and rotated array
// arr: input array
// low and high are 0 and n-1, where n is the size of arr

int minNumber(int arr[], int low, int high)
{
    // when all iterations are over
    if (high < low)  return arr[0];
    
    if (high == low) return arr[low];
    int mid = low + (high - low)/2; 
    
    // check if mid+1 element is the minimum
    if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
      
    // check if mid element is minimum
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
       
    // recurse for the left half
    if (arr[high] > arr[mid])
       return minNumber(arr, low, mid-1);
       
    // recurse for the right half
    return minNumber(arr, mid+1, high);
} 

// { Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends