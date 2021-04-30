// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++


class Solution{
    public:
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int>mp;
        
        //storing all the elements of first array in map.
        for(int i=0;i<N;i++)
        {
            mp[A1[i]]++;
        }
        int j=0;
        for(int i=0;i<M;i++)
        {
            //if any element of second array has value more than 0 in map, we
            //store those elements in array and decrement the count in map.
            while(mp[A2[i]]>0)
            {
                A1[j++]=A2[i];
                mp[A2[i]]--;
            }
        }
        
        //iterating over the map which helps in storing
        //elements in increasing order.
        for(auto it:mp)
        {
            //we store the elements if their frequency is more than 0.
            if(it.second>0)
            {
                //storing elements as many times as their count in output array.
                while(it.second>0)
                {
                    A1[j++]=it.first;
                    it.second--;
                }
            }
        }
        //returning the output.
        return A1;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends