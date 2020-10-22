//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include <bits/stdc++.h>
using namespace std;


int lis(int a[],int n);

int main() {

	int t; cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    
	    cout<<lis(a,n)<<"\n";
	}
	
	return 0;
}

int lis(int a[],int n)
    {
        int lis[n];lis[0]=1;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=0;j<i;j++)
            {
              if(a[j]<a[i])
              lis[i]=max(lis[i],lis[j]+1);
            }
            
        }
            int res =lis[0];
            for(int i=1;i<n;i++)
                res = max(res,lis[i]);
            
            return res;
        
        
    }