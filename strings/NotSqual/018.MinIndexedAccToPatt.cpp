// { Driver Code Starts
// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
    	//using a map as hash table to store first index of all characters.
    	unordered_map<char, int> um;
    	int minIndex = INT_MAX;
    
    	int m = str.size();
    	int n = patt.size();
    
    	//storing first index of each character of string "str" in hash table.
    	for (int i = 0; i < m; i++)
    		if (um.find(str[i]) == um.end())
    			um[str[i]] = i;
    
    	//iterating over the second string "patt".
    	for (int i = 0; i < n; i++)
        {
    		//if current character of string "patt" is found in hash table,
    		//we check if it has the minimum index or not.
    		if (um.find(patt[i]) != um.end() && um[patt[i]] < minIndex)
    		{
    		    //updating minimum index.
    			minIndex = um[patt[i]];
    		}
        }
    
    	//returning the minimum indexed character or -1 if no 
    	//character of "patt" is present in "str".
    	if (minIndex != INT_MAX)
    		return minIndex;
    	else
    		return -1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    Solution obj;
	    int ans = obj.minIndexChar(str, patt);
	    if(ans == -1)cout<<"No character present";
	    else cout<<str[ans];
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends