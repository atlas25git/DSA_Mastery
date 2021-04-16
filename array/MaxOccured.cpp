// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends


class Solution{
    public:
    int arr[1000000];
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
        //Initialising all element of array to 0.
        memset(arr, 0, sizeof(arr));
        
        //Adding 1 at (L[i])th index and subtracting 1 at (R[i]+1)th 
        //index in the array. 
        for(int i = 0;i<n;i++){
            arr[L[i]] += 1;
            arr[R[i]+1] -= 1;
        }
        //Initialise maximum sum as arr[0] and index as -1.
        int msum = arr[0], ind = -1;
        //Finding the prefix sum of the array.
        for(int i = 1;i<=maxx;i++){
            //Finding the prefix sum at every index of the array.
            arr[i] += arr[i-1];
            
            //Updating maximum sum if prefix sum at current index is greater
            //than value stored earlier as maximum sum.
            //Storing the index with maximum prefix sum.
            if(msum < arr[i]){
                msum = arr[i];
                ind = i;
            }
        }
        
        //returning the index with maximum prefix sum which is maximum
        //occuring element in the array.
        return ind;
        
    }
};


// { Driver Code Starts.

int main() {
	
	int t;
	
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n;
	    
	    //taking size of array
	    cin >> n;
	    int L[n];
	    int R[n];
	    
	    //adding elements to array L
	    for(int i = 0;i<n;i++){
	        cin >> L[i];
	    }
	    
	    int maxx = 0;
	    
	    //adding elements to array R
	    for(int i = 0;i<n;i++){
	        
	        cin >> R[i];
	        if(R[i] > maxx){
	            maxx = R[i];
	        }
	    }
	    Solution ob;
	    
	    //calling maxOccured() function
	    cout << ob.maxOccured(L, R, n, maxx) << endl;
	}
	
	return 0;
}  // } Driver Code Ends