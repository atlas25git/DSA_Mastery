// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
        int KthLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            
            if (pq.size() == k && pq.top() < arr[i]) { // if size becomes equal to k
                // and top element is smaller than arr[i]
                pq.pop();
                pq.push(arr[i]);
            } else if (pq.size() < k)
                pq.push(arr[i]);
        }
    
        return pq.top(); // return Kthlargest element
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
}  // } Driver Code Ends