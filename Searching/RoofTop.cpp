// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
        
    // Function to find maximum number of consecutive steps
    int maxStep(int a[], int n){
        int c=0;
        int m=0;
        
        // iterating over the array from element at index 1
        for(int i=1;i<n;i++)
        {
            // check if element is greater than prev
            // if yes, then increase the count
            // This will handle the continuous increasing elements
            if(a[i]>a[i-1])
            c++;
            
            // else, compare and update the max
            else
            {
                m = max(c,m);
                c = 0;
            }
        }
        m=max(c,m);
        
        return m;
        
    }
};

// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout << ob.maxStep(a, n) << endl;
	}
	return 0;
}  // } Driver Code Ends