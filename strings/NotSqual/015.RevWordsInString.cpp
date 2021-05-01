// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        string result = "";
        string curr_word = "";
        vector<string> words;
    
        //tokenizing words
        for (int i = 0; i < s.length(); ++i)
        {
            //if '.' is encountered, we store the word in list.
            if(s[i] == '.')
            {
                words.push_back(curr_word);
                curr_word = "";
            }
            
            else
            {
                curr_word += s[i];
                cout<<"No."<<i<<" "<<curr_word<<"\n";
                
            }
        }
        //storing the last remaining word in list.
        words.push_back(curr_word);
        
        for(auto x: words)cout<<x<<"\n";
        
        //now reversing the whole modified string by adding all 
        //the elements of list in a single string in reverse order.
        for (int i = words.size()-1; i>=0; --i)
        {
            result += words[i];
            if(i!=0)
                result += '.';
        }
        //returning the result.
        return result;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends