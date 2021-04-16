// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
void frequencycount(vector<int>& arr,int n);

 // } Driver Code Ends

class Solution{
    public:

    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencycount(vector<int>& arr,int n)
    { 
        //Decreasing all elements by 1 so that the elements
        //become in range from 0 to n-1.
    	for (int i =0; i<n; i++) 
    		arr[i] = arr[i]-1; 
    	
    	//Using every element arr[i] as index.	
        //Updating the array elements using mathematical formula
        //to find the frequencies of all elements from 1 to N.
    	for (int i=0; i<n; i++) 
    	    //Adding n to element present at arr[i]%n to keep
    	    //track of count of occurrences of arr[i].
    	    //since we're adding just n the original no. 
    	    //would be available with modulo operation
    		arr[arr[i]%n] += n; 
    
        //Calculating the frequency of each element.
    	for (int i =0; i<n; i++) 
    	    //Finally dividing the array elements by n to find the frequency.
    		arr[i] = arr[i]/n;
    }

};


// { Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int n;
	    //size of array
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    //adding elements to the vector
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

        Solution ob;
        //calling frequncycount() function
		ob.frequencycount(arr,n); 
		
		//printing array elements
	    for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
	}	
	return 0; 
}




  // } Driver Code Ends