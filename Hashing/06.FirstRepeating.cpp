// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
        //Function to return the position of the first repeating element.
    int firstRepeated(int *arr, int n) {
        bool flag = false;
        int ans = -1;
        
        //using map to store frequency of each element.
        unordered_map<int, int> m;
        
    	//storing the frequency of each element in map.         
        for(int i =0;i<n;i++)
            m[arr[i]]++;
        
        //iterating over the array elements.   
        for(int i = 0 ; i < n ; i++){
            
            //if frequency of current element in map is greater than 1,
            //then we store the index and break the loop.
            if(m[arr[i]] > 1){
                ans = i+1;
                break;
            }
        }
        //returning the position of the first repeating element.
        return ans;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
        Solution ob;    
        cout << ob.firstRepeated(arr,n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends