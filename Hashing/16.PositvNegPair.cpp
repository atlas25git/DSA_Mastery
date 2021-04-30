// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    { 
    	vector<int> result; 
    	//using map to store the count of absolute value of numbers.
    	unordered_map<int, int> ump; 
    
        //iterating over the array.
    	for (int i = 0; i < n; i++) { 
    	    
    	    //if the count of absolute value of current element is 0 in
    	    //map, we store that element in map with 1 as count.
    		if (ump[abs(arr[i])] == 0) {
    			ump[abs(arr[i])] = 1; 
    		}
            //else the absolute value of current element is present twice 
            //so the pair of positive and negative number is present.
    		else { 
    		    
    		    //we store the pair in the list.
    			result.push_back((-1)*abs(arr[i])); 
    			result.push_back(abs(arr[i])); 
    			ump[abs(arr[i])] = 0; 
    		} 
    	} 
    	//returning the list.
    	return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size()!=0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout<<0<<endl;
    }

    return 0;
}  // } Driver Code Ends