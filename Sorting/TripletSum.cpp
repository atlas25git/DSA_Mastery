// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to find minimum difference between any pair of elements in an array.
    
    
    void merge(int* arr, int l, int mid, int r)
    {
        int size1 = mid -l +1;
        int size2 = r-mid;
        
        int aux1[size1],aux2[size2];
        
        for(int i=0;i<size1;i++){
            aux1[i]=arr[l+i];    
        }
        for(int i=0;i<size2;i++){
            aux2[i] = arr[mid+1+i];
        }
        
        int k=0,n=0,res = l;
        
        while(k<size1 && n<size2)
        {
            if(aux1[k]<aux2[n])
            {
                arr[res++]=aux1[k++];
            }
            else{
                arr[res++]=aux2[n++];
            }
        }
        
        while(k<size1)
        {
            arr[res++]=aux1[k++];
        }
        while(n<size2)
        {
            arr[res++]=aux2[n++];
        }
    }
    
    void mergesort(int* arr, int l, int r){
        
        if(l<r)
        {
            int mid = (l+r)/2; //cout<<"mid="<<" "<<mid<<" ";
            mergesort(arr,l,mid);
            mergesort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
    
    int MinimumDifference(int arr[], int n)
    {
        mergesort(arr,0,n-1);
        //cout<<"#########################"<<endl;
        //for(int i=0;i<n;i++)
        //cout<<" "<<arr[i]<<":";
        
        int mine = INT_MAX;
        for(int i=0;i<n-1;i++){
            mine = min(mine,arr[i+1]-arr[i]);
        }
        return mine;
    }
};

// { Driver Code Starts.
    
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n]; 
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int diff = ob.MinimumDifference(arr, n);
	    cout << diff << endl;
	}
	return 0;
}  // } Driver Code Ends