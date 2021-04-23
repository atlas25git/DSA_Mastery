// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int diff = 0;
//Function to compare values while sorting. 
bool mycomparator(int a, int b){
    
    //storing the difference of first number with diff.
    int a_diff = abs(a - diff);
    
    //storing the difference of second number with diff.
    int b_diff = abs(b - diff);
    

    //if a_diff is smaller than b_diff, it means we need to put a_diff 
    //so we return true.
    if(a_diff < b_diff)
    return 1;
            
    //else we return false.
    return 0;
    }
    
class Solution{
    public:
    //Function to sort the array according to difference with given number.
    void sortABS(int A[],int N, int diff2)
    {
        diff = diff2;
        //using stable sort function over the array.
        stable_sort(A, A+N, mycomparator);
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    
	    int N, diff;
	    cin>>N>>diff;
	    int A[N];
	    
	    for(int i = 0; i<N; i++)
	        cin>>A[i];
	   
	    Solution ob;
	   
	    ob.sortABS(A, N, diff);
	    
	    for(int & val : A)
	        cout<<val<<" ";
	    cout<<endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends