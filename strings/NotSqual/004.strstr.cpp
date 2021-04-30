// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


int strstr(string s, string x)
{
    if (x[0] == '\0') 
    return 0;
    
    //iterating over given string s to search for string x.
    for (int i = 0; s[i] != '\0'; i++) 
    {
        bool isMatched = true;
        
        //checking for string x from current index i in the string s.
        for (int j = 0; x[j] != '\0'; j++) 
        {
            if(s[i + j] == 0) 
            return -1;
            
            //if any character doesn't match, we break the loop.
            if(s[i + j] != x[j]) {
                isMatched = false;
                break;
            }
        }
        
        //if string x is found, then we return the starting index.
        if (isMatched) 
        return i;
    }
    //returning -1 if string x is not found.
    return -1;
}