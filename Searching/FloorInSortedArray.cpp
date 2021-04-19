// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
         
    
    // Function to find floor of given element
    int findFloor(vector<long long> v, int n, long long x){
        auto itr = v.begin();
        auto last = v.begin();
        
        // advance function is used to move the iterator to n steps
        advance(last, n);
        
        auto it = lower_bound(v.begin(), last, x);
        
        // check if lower_bound function()
        // returns the element equal to x
        // then return the number of element
        // in between
        if(*it == x){
            return (it-itr);
        }
        
        // else return the number of element in between -1
        // because, since floor doesn't exists, then element just before the
        // inserted will be its floor.
        // Also, it will return -1 for the elements which is even not there in the array
        else
        //since lowerbound return not less than as in [ equal value could also come
        //but if ain't equal value comes then we gotta take the one which is just
        //behind.
            return ((it-1)-itr);
        
    }
};


// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}  // } Driver Code Ends