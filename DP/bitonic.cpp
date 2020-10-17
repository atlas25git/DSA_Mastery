//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
//https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	   //we find lis, 
	   //then we find lds, that is lis from right
	   //now take the maximum of their indice's element value -1;
	   int s=nums.size();
	   return lis(nums,s);
	   
	}
	
	int lis(vector<int> a,int n)
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
        
        int lds[n];lds[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            lds[i]=1;
            for(int j=n-1;j>i;j--)
            {
              if(a[j]<a[i])
              lds[i]=max(lds[i],lds[j]+1);
            }
            
        }
        
            int res =lis[0] + lds[0] -1;
            for(int i=1;i<n;i++)
                res = max(res,lis[i]+lds[i] -1);
            
            return res;
        
        
    }



};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends