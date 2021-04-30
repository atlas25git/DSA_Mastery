// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        int m = str1.length(), n = str2.length();
        
        if (m != n)
            return false;
        
        //using a boolean array to mark visited characters in str2.
        bool marked[MAX_CHARS] = {false};
        
        //using map to store mapping of every character from str1 to
        //that of str2. Initializing all entries of map as -1.
        int map[MAX_CHARS];
        memset(map, -1, sizeof(map));
        
       
        for (int i = 0; i < n; i++)
        {
            //if current character of str1 is seen first time in map.
            if (map[str1[i]] == -1)
            {
                //if current character of str2 is already
                //seen, one to one mapping is not possible.
                if (marked[str2[i]] == true)//checking if ch in str 2 is avl.
                    return false;
                
                //marking current character of str2 as visited.
                marked[str2[i]] = true;///reserving it for mapping of the first occr. in str1
                
                //storing mapping of current characters.
                map[str1[i]] = str2[i];
            }
            
            //if this isn't first appearance of current character in str1 then
            //checking if previous appearance mapped to same character of str2.
            else if (map[str1[i]] != str2[i])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends