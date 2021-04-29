// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to return non-repeated elements in the array.
    vector<int> printNonRepeated(int arr[],int n)
    {
        //using map to store frequency of each element.
        unordered_map<int,int>mp;
    	
    	//storing the frequency of each element in map. 
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> v;
        //iterating over the array elements.
        for(int i=0;i<n;i++)
        {
            //if frequency of current element in map is 1,
            //then we store it in the vector.
            if(mp[arr[i]]==1)
            {
                v.push_back(arr[i]);
            }
        }
        
        //returning the vector.
        return v;
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
	    
	    vector<int> v;
	    Solution obj;
	    v = obj.printNonRepeated(arr,n);
	    
	    for(int i=0;i<v.size();i++)  
	        cout<<v[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}

  // } Driver Code Ends