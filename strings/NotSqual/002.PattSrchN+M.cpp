// { Driver Code Starts
// C++ program for Naive Pattern 
// Searching algorithm 
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) 
    { 
    	int M = pat.length();  
        int N = txt.length();  
        int i = 0;  
      
        //iterating over given text to search for pattern.
        while (i <= N - M)  
        {  
            int j;  
      
            //checking for pattern from current index i in the text. 
    		//if any character, differs we break the loop.
            for (j = 0; j < M; j++)  
                if (txt[i + j] != pat[j])  
                    break;  
      
            //if loop is not broken it means that we found the
            //pattern so we return true.
            if (j == M) 
            {  
                return true;
            }  
            
            //else sliding the pointer by j indexes (or by 1 if j=0).
            else if (j == 0)  
                i = i + 1;  
            else
                i = i + j; 
        }
        //returning false if pattern is not found.
        return false;
    }
};




// { Driver Code Starts.

// Driver Code 
int main() 
{ 
	
	int t;
	cin >> t;
	
	while(t--){
	    string s, p;
	    cin >> s >> p;
	    Solution obj;
	    if(obj.search(p, s)) cout << "Yes"; else cout << "No"; cout << endl;
	}
	
	return 0; 
}  // } Driver Code Ends