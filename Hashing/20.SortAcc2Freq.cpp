// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    unordered_map<int, int> m;
    
    //Function used in sorting vector elements first according to frequency
    //and if it is same for both values, then smaller number comes first.
    static bool sortByVal1(const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second) return a.first < b.first;
        
        return a.second > b.second;
    }
    
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n){
        
        vector<pair<int, int>> v;
        
        //using map to keep count of the elements.
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }
        
        //copying the elements and their count from map to vector.
        copy(m.begin(), m.end(), back_inserter(v));
        
        //sorting the vector according to frequency.
        sort(v.begin(), v.end(), sortByVal1);
        vector<int> ans;
        
        for(int i = 0;i<v.size();i++){
            //storing elements as many times as their count in output vector.
            for(int j = 0;j<v[i].second;j++){
                ans.push_back( v[i].first );
            }
        }
        m.clear();
        
        //returning the output.
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends