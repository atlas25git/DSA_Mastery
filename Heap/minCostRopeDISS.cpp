// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
        long long minCost(long long arr[], long long n) {
        // making Minheap
        priority_queue<long long, vector<long long>, greater<long long> > pq(
            arr, arr + n);
    
        long long res = 0;
    
        while (pq.size() > 1) {
            long long first = pq.top(); // storing first
            pq.pop();
            long long second = pq.top(); // storing second
            pq.pop();
    
            res += first + second;
            // push first and second back in priority queue
            pq.push(first + second);
        }
    
        return res;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends