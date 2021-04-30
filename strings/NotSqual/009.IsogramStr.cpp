// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string is Isogram or not.
    bool isIsogram(string s)
    {
        int hash[26]={0};
        
        //iterating over the string.
        for(int i=0;i<s.length();i++)
        {
            //incrementing the count of characters in hash table.
            hash[s[i]-'a']++;
            
            //if count of any character is greater than 1 then 
            //string is not isogram so we return false.
            if(hash[s[i]-'a']>1)
            return false;
        }
        //returning true if no character occurs more than once.
        return true;
    }

};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.isIsogram(s)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends