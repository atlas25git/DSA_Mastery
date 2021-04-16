// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    //Function to find minimum adjacent difference in a circular array.
    int minAdjDiff(int arr[], int n){
        //Storing the difference of first and second element in the array.
        int res = abs(arr[0]-arr[1]); 
        //Iterating from the 2nd index to the last index.
        for(int i = 2; i < n; i++) 
        {
            //Updating the minimum value whenever we get a smaller adjacent
            //difference than previously stored value.
            res = min(res, abs(arr[i]-arr[i-1])); //finding min
        }
        //Finally checking the difference between last and first element
        //as it's a circular array.
        res = min(res, abs(arr[0]-arr[n-1])); 
        
        //returning the final answer.
        return res;
        
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; //Input testcases
    
    while(t--) //While testcases exist
    {
        int n;
        cin>>n; //Input size of array
        
        int arr[n]; //Array of size n
        
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i]; //input elements of array
        }
        Solution ob;
        
        cout << ob.minAdjDiff(arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends