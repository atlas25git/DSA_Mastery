// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        vector<int>hash(26,0);
        
        //using hash table to store count of each character.
        for(auto i: str)
        hash[i-'a']++;
        int maxi = 0;
        char ch;
        
        //iterating over the hash table.
        for(int i = 0; i < 26; i++)
        {
            //we keep storing the maximum value in hash 
            //table and its corresponding character.
            if(hash[i] > maxi){
                maxi = hash[i];
                ch = i + 'a';
            }
        }
        //returning the character with maximum occurrences.
        return ch;
    }
};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends