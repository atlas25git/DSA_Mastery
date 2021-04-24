// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    
    int binarySearch(int arr[], int l, int r, int x){
        
        if(r >= l){
    
            int mid = l + (r-l)/2;
            
            //We check for the element also at mid-1 and mid+1 since  
            //some elements are moved to either of the adjacent positions,
            //i.e, maybe to the arr[i+1] or arr[i-1].
            
            //If the element is present at any one of the 3 middle
            //positions i.e. (mid, mid-1, mid+1), we return the index.
            
            if(arr[mid] == x){
                return mid;
            }
            
            if(mid > l && arr[mid-1] == x){
                return mid-1;
            }
            
            if(mid < r && arr[mid+1] == x){
                return mid+1;
            }
            
            //If element is smaller than element at mid, then it can only be 
            //present in left subarray so we call the function recursively.
            if(arr[mid] > x){
                return binarySearch(arr, l, mid-2, x);
            }
            
            //If element is greater than element at mid, then it can only be 
            //present in right subarray so we call the function recursively.
            return binarySearch(arr, mid+2, r, x);
        }
        
        //If the element is not present in the array we return -1.
        return -1;
        
    }
    
    //Function to find index of element x in the array if it is present.
    int closer(int arr[],int n, int x)
    {
        return binarySearch(arr, 0, n-1, x);
    }
    

};


// { Driver Code Starts.

int main() {
    
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    int x;
	    cin >> x;
	    Solution obj;
	    int res = obj.closer(arr,n,x);
	    
	    cout << res << endl;
	}
	
	return 0;
}  // } Driver Code Ends