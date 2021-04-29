// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
         
        //using a map to store frequency of elements.
        unordered_map<ll,ll> mp;
        
        //incrementing frequencies of elements present in first array in the map. 
        for(ll i=0;i<N;i++)
            mp[A[i]]++;
        
        //decrementing frequencies of elements present in second array in the map.
        for(long long i=0;i<N;i++) 
            mp[B[i]]--;
            
        //iterating over the map.
        for(auto i=mp.begin();i!=mp.end();i++) {
            
            //if frequency of any element in map now is not zero it means that its 
            //count in two arrays was not equal so the arrays are not equal.
            if(i->second!=0) {
                
                //returning false since arrays are not equal.
                return false;
            }
        }
        //returning true if arrays are equal.
        return true;
            
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends