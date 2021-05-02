// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define MOD 1000000007
class Solution
{
    public:
    //Function to generate the list of factorials.
    void initializeFactorials(int totalLen, vector<int> &fact) 
    {
        long long int factorial = 1;
        fact.push_back(1); 
        for (int curIndex = 1; curIndex < totalLen; curIndex++)
        {
            factorial = (factorial * curIndex) % MOD;
            fact.push_back(factorial);
        }
        return;
    }
    
    //Function to find lexicographic rank of a string.
    int findRank(string S) 
    {
        int charCount[256];
        memset(charCount, 0, sizeof(charCount));
        
        //counting the characters of the string.
        for (int i = 0; i < S.length(); i++)
        {
            charCount[S[i]]++;
            
            //returning 0 if any character is repeated.
            if(charCount[S[i]]>1)
            return 0;
        }
        

        vector<int> fact;
        initializeFactorials(S.length() + 1, fact);

        long long int rank =  1;
        
        //iterating over the string.
        for (int i = 0; i < S.length(); i++) 
        {
            int less = 0;
            for (int ch = 0; ch < S[i]; ch++) {
                less += charCount[ch];
            }
            //calculating the rank.
            rank=(rank+((long long)fact[S.length()-i-1]*less))%MOD;
            
            //updating the character count.
            charCount[S[i]]--;
        }
        //returning the rank.
        return rank;
    }
};

// { Driver Code Starts.


int main()
{
    string S;
    int t;
    cin>>t;
    while(t--)
    {
     
        cin>>S;
        Solution obj;
        cout<<obj.findRank(S)<<endl;
    }
}
  // } Driver Code Ends