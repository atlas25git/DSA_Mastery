//https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m,int n);

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;cin>>m>>n;
	    string s1,s2; cin>>s1>>s2;
	    cout<<lcs(s1,s2,m,n)<<"\n";
	}
	
}

int lcs(string s1, string s2, int m,int n)
    {
        
        //Recursive approach
    //     if(m==0||n==0)return 0;
    //     int res=0;
    //     if(s1[m-1]==s2[n-1])res= 1+lcs(s1,s2,m-1,n-1);
    //     else res= max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    //   return res;
       
       //memoization based solution 
       //here we make array of m+1,n+1 because we need to use m,n as indices.
       //In memoization we simply modify the recursive code with memory to store the pre computed results.
        // int memo[m+1][n+1];
        // for(int i=0;i<m+1;i++)
        // {
        //     for(int j=0;j<n+1;j++)
        //     {
        //         memo[i][j]=-1; //intitalizing with a non possible lcs value
        //     }
        // }
        
        // if(memo[m][n]!=-1)return memo[m][n];
        // if(m==0||n==0)memo[m][n]=0;
        // else{
        //     if(s1[m-1]==s2[n-1])memo[m][n]=1+lcs(s1,s2,m-1,n-1);
        //     else memo[m][n]= max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
        // }
        // return memo[m][n];
      
      //tabulation based solutin, here we totally remove recursive nature of function by forming a table.
      //building it up from the base case.
      //here we make dp array of dimension m+1,n+1, because here we need to store the base case too.
         int dp[m+1][n+1];
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
        
        
    }