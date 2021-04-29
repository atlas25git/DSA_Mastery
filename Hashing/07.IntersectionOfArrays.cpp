// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to return the count of the number of elements in
    //the intersection of two arrays.
    int NumberofElementsInIntersection (int a[], int b[] , int n, int m)
    {
        //using set to store the elements.
    	unordered_set<int> s1;
        int count = 0;
        
        //we insert all the elements of first array in set s1. 
    	for(int i=0;i<n;i++)
    		s1.insert(a[i]);
        
        //iterating over the second array.
    	for(int i=0;i<m;i++)
    	{
    	    //if current element already exists in set, we update the counter.
    		if(s1.find(b[i]) != s1.end()){
    		    
    		    //erasing element from set because if same element is present 
    		    //again in the array we don't need to count it again. 
    		    s1.erase(b[i]);
    		    
    		    //incrementing the counter. 
    		    count++;
    		}
    	}
    	//returning the counter.
    	return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
		Solution ob;
		cout << ob.NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
}  // } Driver Code Ends