// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution{
    public:
    //Function to return the count of non-repeated elements in the array.
    int countNonRepeated(int arr[], int n)
    {
        //using map to store frequency of each element.
        unordered_map<int,int>mp;
        long long counter=0;
        
        //storing the frequency of each element in map.
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        //iterating over the array elements.
        for(int i=0;i<n;i++)
        {
            //if frequency of current element in map is 1,
            //then we increment the counter.
            if(mp[arr[i]]==1)
            {
                counter++;
            }
        }
        //returning the count of non-repeated elements.
        return counter;
    }

};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    cout<<obj.countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}
  // } Driver Code Ends