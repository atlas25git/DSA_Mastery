// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a)
    {
        int count = 0;
        for(int i=0;i<n;i++)
        {
            //counting number of 1's in the string.
            if(a[i]=='1')
                count++;
        }
        //returning count of possible pairs among total number of 1's.
        return (count*(count-1))/2;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends