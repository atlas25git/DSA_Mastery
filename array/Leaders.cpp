// { Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> v;
        
        long long max = a[n-1];
        
        //We start traversing the array from last element.
        for(long long i =n-1; i >= 0; i--){
            //Comparing the current element with the maximum element stored. 
            //If current element is greater than max, we add the element.
            if(a[i] >= max){
                //Updating the maximum element.
                max = a[i];
                //Storing the current element in vector for leaders.
                v.push_back(max);
            }
        }
        //Finally reversing the vector in which leaders are stored.
        reverse(v.begin(), v.end());
        //returning the vector.
        return v;
        
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends