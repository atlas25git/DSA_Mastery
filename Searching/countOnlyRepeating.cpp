// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// arr : given array
// n : size of the array

class Solution{
  public:
//Back-end complete function template for C++
    
    pair<int, int> findRepeating(int *arr, int n){
        //basically we're just using the formula that if all the elements 
        //distinct and are just increasing by 1, then all the n elements would be 
        //unique, if they ain't and just one is repeating then 
        //we can calculate he no. of times an element repeats by the implemntation of
        //formula
        
        // if no elements
        if(n == 0){
            return {0, 0};
        }
        
        // if one element in the array
        // or array with no repeating elements
        if(n-(arr[n-1]-arr[0]) == 1){
            return {-1, -1};
        }
        
        int lo = 0, hi = n-1;
        int mid = 0;
        
        // binary search to find the element which is repeating
        while(lo < hi){
            
            mid = (lo+hi)/2;
            
            //the condition inside if is applied for the divided array
            
            if(arr[mid] >= mid + arr[0]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        
        return {arr[mid], n-(arr[n-1]-arr[0])};
        
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);
	    
	    cout << ans.first << " " << ans.second << endl;
	    
	}
	
}  // } Driver Code Ends