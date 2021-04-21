// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

 // } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
{    
    //base case
    if (x == 0 || x == 1) 
       return x;
 
    long long int start = 1, end = x, ans;   
    
    // binary search to find square root of a number
    while (start <= end) 
    {        
        long long mid = (start + end) / 2;
        
        // check if mid*mid == x
        if (mid*mid == x)
            return mid;
        
        // if mid*mid < x, then iterate on the upper half
        if (mid*mid < x) 
        {
            start = mid + 1;
            ans = mid;
        } 
        // else, iterate for the lower half
        else
            end = mid - 1;        
    }
    return ans;
}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
  // } Driver Code Ends