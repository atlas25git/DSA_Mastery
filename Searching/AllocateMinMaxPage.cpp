// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
  public:
    
    bool isFeasible(int* arr,int n,int m,int mid)
    {
        int req =1,currsum =0;
        for(int i=0;i<n;i++)
        {
            if(currsum+arr[i]>mid)
            {
                req++;
                currsum = arr[i];
            }
            else currsum += arr[i];
        }
        
        if(req>m)return false;
        return true;
        
    }
  
    int findPages(int arr[], int n, int m) {
        
        int maxE=INT_MIN,sum;
        for(int i=0;i<n;i++)
        {
            maxE=max(arr[i],maxE);
            sum += arr[i];
        }
        //cout<<"maxE"<<" "<<maxE<<" "<<"sum"<<sum<<"\n";
        int low=maxE,high=sum,res=0;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            //cout<<"mid"<<" "<<mid<<"\n";
            
            if(isFeasible(arr,n,m,mid))
            {
                high = mid-1;
                res= mid;
            }
            else low = mid+1;
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends