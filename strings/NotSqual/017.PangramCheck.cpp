// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string str)
    {
        //using a hash table to mark the characters present in the string.
        vector<bool> mark(26, false);
        int index;
    
        //iterating over the string.
        for (int i=0; i<str.length(); i++)
        {
            //if we get uppercase character, we subtract 'A' from it
            //to get its index (in terms of 0 to 25).
            if ('A' <= str[i] && str[i] <= 'Z')
                index = str[i] - 'A';
    
            //if we get lowercase character, we subtract 'a' from it
            //to get its index (in terms of 0 to 25).
            else if('a' <= str[i] && str[i] <= 'z')
                index = str[i] - 'a';
    
            //marking index of current character as true in hash table.
            mark[index] = true;
        }
    
        //returning false if any letter of alphabet is unmarked.
        for (int i=0; i<=25; i++)
            if (mark[i] == false)
                return (false);
    
        //if all letters of alphabet are present then returning true.
        return (true);
    }


};

// { Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}
  // } Driver Code Ends