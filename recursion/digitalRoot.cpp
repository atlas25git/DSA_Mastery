// { Driver Code Starts
//Initial Template for C++


#include <iostream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    //Complete this function
   int sumDigits(int n)
{
    // returning n if n / 10 is 0
    if(n / 10 == 0)
        return n;
    // else adding digit sum
    else
        return n % 10 + sumDigits(n/10);
}
    
    
// function to calculate the single digit answer
int digitalRoot(int n)
{
    // if n is less than n then 
    // returning the n
    if(n<10)
        return n;
    // else calling sumDigits function
    else
        return digitalRoot(sumDigits(n));
}
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;//taking testcases
	while(T--)
	{
	    int n;
	    cin>>n;//taking number n
	    
	    //calling digitalRoot() function
	    Solution obj;
	    cout<<obj.digitalRoot(n)<<endl;
	    
	    
	}
	return 0;
}  // } Driver Code Ends