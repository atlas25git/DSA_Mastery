// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

class Solution
{
    public:
    //Function to find repeated character whose first appearance is leftmost.
    int repeatedCharacter (string s) 
    { 
        //using hash table to store count of each character.
        int firstIndex[256]; 
        for (int i = 0; i <256; i++) 
            firstIndex[i] = -1; 
      
        int res = INT_MAX; 
        
        //iterating over the string.
        for (int i = 0; i < s.length(); i++) 
        { 
            //if current character is not present in hash table,
            //we store its position or first appearance in hash table.
            if (firstIndex[s[i]] == -1) 
               firstIndex[s[i]] = i;
               
            //else we compare the position stored in hash table with 
            //minimum value stored earlier and store their minimum.
            else
               res = min(res, firstIndex[s[i]]); 
        } 
        //returning the result.
        return (res == INT_MAX) ? -1 : res; 
    } 
};

// { Driver Code Starts.


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    Solution obj;
	    int index = obj.repeatedCharacter(s); 
        if (index == -1) 
            cout<<-1<<endl;
        else
            cout<<s[index]<<endl;
	}
	return 0;
}
  // } Driver Code Ends