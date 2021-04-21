// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
        int countOnes(int arr[], int n)
    {
        int low = 0, high = n-1;
        int mid = (low+high)/2;
        
        // binary search to count 1s
        while(low <= high){
            mid = (low+high)/2;
            
            // check if mid is 1
            if(arr[mid] == 1 && mid+1 < n && arr[mid+1] == 1){
                low = mid+1;
            }
            
            // if mid is not 0, then iterate for lower half
            else if(arr[mid] == 0){
                high = mid-1;
            }
            
            // else iterate for upper half
            else if(arr[mid] == 1 && ((mid+1 < n && arr[mid+1] == 0) || (mid == n-1))){
                return mid+1;
            }
        }
        
        return 0;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends