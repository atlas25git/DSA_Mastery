// { Driver Code Starts
#include<bits/stdc++.h>
#define br char xx; cin>>xx; cout<<xx<<endl;
#define lli long long int
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of characters which Ishaan must insert  
    //such that string doesn't have three consecutive same characters.
    int modified(string a)
    {
        int ans, same;
        ans=0;
        same=1;
        //whole idea is that for every three ch. found same
        //we add a charachter and return the total no. of them required
        //Ofc for n<3 the calculative prowess would be 0.
        
        //checking for any three consecutive same characters and if they are
        //found then we increment the count of characters to be added.
        for(int i=1;a[i];i++)
        {
            if(a[i]==a[i-1]){
                same++;
            }
            else{
                ans+=(same-1)/2;
                same=1;
            }
        }
        ans += (same-1)/2;
        //returning the answer.
        return ans;
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    string a;
    while(t--){
        cin>>a;
        Solution obj;
        cout<<obj.modified(a)<<endl;
    }
    return 0;
}
  // } Driver Code Ends