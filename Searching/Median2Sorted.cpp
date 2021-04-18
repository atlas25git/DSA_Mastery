// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// arr : given array with size n 
// brr : given array with size m
class Solution{
  public:
    int findMedianUtil(int* arr,int n,int* brr,int m)
    {
        int begin =0, end=n;
        int max1, max2, min1,min2,i1,i2;
        while(begin<=end)
        {
            i1 = (begin+end)/2;
            i2 = (n+m+1)/2 - i1;
            
            min1 = (i1==n)?INT_MAX:arr[i1];
            max1 = (i1==0)?INT_MIN:arr[i1-1];
            min2 = (i2==m)?INT_MAX:brr[i2];
            max2 = (i2==0)?INT_MIN:brr[i2-1];
            
            if( max2 <= min1 && max1 <= min2)
            {
                if((m+n)&1)
                    return max(max1,max2);
                return (max(max1,max2)+ min(min1,min2))/2;
            }
            
            else if(max1>min2) end = i1-1;
            else begin=i1+1;
            
        }
    }
  
    int findMedian(int arr[], int n, int brr[], int m){
        
        if(n<m)
            return findMedianUtil(arr,n,brr,m);
        return findMedianUtil(brr,m,arr,n);
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int arr[n];
	    int brr[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> brr[i];
	    }
	    Solution obj;
	    if(n < m)
	        cout << obj.findMedian(arr, n, brr, m) << endl;
	   else
	        cout << obj.findMedian(brr, m, arr, n) << endl;
	    
	}

}  // } Driver Code Ends