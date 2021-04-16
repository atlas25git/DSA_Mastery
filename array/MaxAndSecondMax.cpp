// { Driver Code Starts
//Initial Template for C++

// CPP code to find largest and 
// second largest element in the array

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
     

class Solution{
  public:
/*  Function to find largest and second largest element
*   sizeOfArray : number of elements in the array
*   arr = input array
*/
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        int max = INT_MIN, max2= INT_MIN;
        
        //Iterating through the array and comparing the elements
        // to find max and second max.
        for(int i = 0; i < sizeOfArray; i++){
            
            //If current element is greater than max, we update the max and second max.
            //second max becomes equal to max and max becomes equal to the current element.
            if(arr[i] > max){
                max2 = max;
                max = arr[i];
            }
            //Else If current element is greater than max2 and is not equal to max.
            //we update second max as current element.
            else if(arr[i] > max2 && arr[i] != max){
                max2 = arr[i];
            }
        }
        
        //If no second max exists, we assign -1 to second max.
        if(max2 == INT_MIN){
            max2 = -1;
        }
        //returning the max and second max element in vector form.
        vector<int> temp(2);
        temp[0] = max;
        temp[1] = max2;
        return temp;
    }
};

// { Driver Code Starts.

// Driver Code
int main() {
	
	// Testcase input
	int testcases;
	cin >> testcases;
    
    // Looping through all testcases
	while(testcases--){
	    int sizeOfArray;
	    cin >> sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    // Array input
	    for(int index = 0; index < sizeOfArray; index++){
	        cin >> arr[index];
	    }
	    Solution obj;
	    vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
	    cout<<ans[0]<<' '<<ans[1]<<endl;
	}
	
	return 0;
}  // } Driver Code Ends