// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if a string is subsequence of other string.
    bool isSubSequence(string A, string B)
    {
        int i = 0, j = 0;
        
        //traversing both strings with two pointers.
        while (i < B.length() && j < A.length())
        {
            //if current character matches in both string 
            //then we move ahead in first string.
            if (A[j] == B[i])
                j += 1;
                
            //moving ahead in second string.
            i += 1;
        }
        
        //if j pointer equals length of first string A then it
        //is subsequence of B so we return true else false.
        return (j == A.length());
    }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string A, B; cin>>A>>B;
	    Solution ob;
	    bool ans = ob.isSubSequence(A, B);
	    if(ans)
	        cout<<"True"<<endl;
	    else
	        cout<<"False"<<endl;
	}
	return 0;
}  // } Driver Code Ends