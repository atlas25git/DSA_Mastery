// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int a[], int n){
        
        long long maxh = 0, maxf = INT_MIN;
        
        //Iterating over the array.
        for(int i=0;i<n;i++) 
            {
                //Updating max sum till current index.
                maxh+=a[i];
                //Storing max sum so far by choosing maximum between max 
                //sum so far and max till current index.
                maxf=max(maxh,maxf); 
                
                //If max sum at current index is negative, we do not need to add
                //it to result so we update it to zero.
                if(maxh<0)
                    maxh=0;
    
            }
            //returning the result.
            return maxf;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}