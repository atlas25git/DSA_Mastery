// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    { 
    	int i = n-1, j = 0; 
    	while ( i >= 0 && j < m ) 
    	{ 
    	    //if given number is found, we return true.
    		if ( matrix[i][j] == x ) 
    			return true; 
    		//if current element is greater than given number, we 
    		//decrease i pointer else we increase j pointer.
    		if ( matrix[i][j] > x ) 
    			i--; 
    		else 
    			j++; 
    	} 
    	//if we reach here, it means given number is not
    	//present in matrix so we return false.
    	return false; 
    } 
};

// { Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

  // } Driver Code Ends