// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int a[], int d, int n){
        
        //First reversing d elements from starting index.
        reverse(a, a+d);
        //Then reversing the last n-d elements.
        reverse(a+d, a+n);
        //Finally, reversing the whole array.
        reverse(a, a+n);
        
    }

};

// { Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends