// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution{
    public:
        // comparison function defined for the priority queue 
        struct compare 
        { 
        bool operator()(pair<int, int> p1, pair<int, int> p2) 
        { 
        	// if frequencies of two elements are same 
        	// then the larger number should come first 
        	if (p1.second == p2.second) 
        		return p1.first < p2.first; 
        		
        	// insert elements in the priority queue on the basis of 
        	// decreasing order of frequencies	 
        	return p1.second < p2.second;	 
        } 
        }; 
        
        // Function to print the k numbers with most occurrences 
        int kMostFrequent(int arr[], int n, int k) 
        { 
        // unordered_map 'um' implemented as frequency hash table  
        unordered_map<int, int> um;
        for (int i = 0; i<n; i++) 
        	um[arr[i]]++; 
        
        // store the elements of 'um' in the vector 'freq_arr'	 
        vector<pair<int, int> > freq_arr(um.begin(), um.end()); 
        
        priority_queue<
                        pair<int, int>, 
                        vector<pair<int, int>>, 
                        compare
                      > 
                      pq(um.begin(), um.end()); 
        
        // display the the top k numbers 
        int ans = 0;
        for (int i = 1; i <= k; i++) 
        { 
        	ans += pq.top().second;
        	pq.pop(); 
        }
        return ans;			 
        } 
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
} 
  // } Driver Code Ends