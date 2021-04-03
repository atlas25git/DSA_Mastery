// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    
    
    // public:
    //     vector<int> kLargest(int arr[], int n, int k)
    // {
    //     // code heresort
    //     vector<int> v;
    //     sort(arr,arr+n,greater<int>());
    //     for(int i = 0 ;i<k;i++)
    //     v.push_back(arr[i]);
    //     return v;
    // }
    
    public:
        vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int> > q; // Minheap
        vector<int> v;
        
        for(int i = 0; i < n;i++){
            if(q.size() == k){ // if size becomes equal to k
                if(q.top() < arr[i]){ // if top element is smaller than arr[i]
                    q.pop();   
                    q.push(arr[i]);  
                }
            }
            else
                q.push(arr[i]);
        }
        
        // push all heap elements in vector
        while(!q.empty()) v.push_back(q.top()), q.pop(); 
        
        reverse(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int> result = ob.kLargest(arr, n, k);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends