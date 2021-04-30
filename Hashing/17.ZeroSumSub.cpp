// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++


class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
     ll findSubarray(vector<ll> arr ,int n) {
        
         ll sum=0, counter=0; 
         
         //using map to store the prefix sum which has appeared already.
         unordered_map<ll,ll>mp;
        
            //iterating over the array.
            for(int i=0;i<n;i++)
            {
                //storing prefix sum.
                sum+=arr[i];
                
                //if prefix sum is zero that means we get a subarray with sum=0.
                if(sum==0) 
                {
                    //incrementing the counter.
                    counter++; 
                }
                
                //if prefix sum is already present in map then it is repeated 
                //which means there is a subarray whose summation is 0.
                if(mp.count(sum)!=0) 
                {
                   //we add the value at prefix sum in map to counter.
                   counter+=mp[sum]; 
                }
                
                //incrementing the count of prefix sum obtained in map.
                mp[sum]++; 
            }
           //returning the counter.
           return counter ;
}
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends