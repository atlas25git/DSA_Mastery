#include<bits/stdc++.h>
using namespace std;


       
  
    int maxCuts(int n, int a, int b, int c) 
    { 
        
    //  int dp[n+1];
     
    //  dp[0] =0;
     
    //  for(int i = 1; i<=n; i++)
    //  {
    //      dp[i] = -1;
         
    //      if(i-a >=0) dp[i] = max(dp[i],dp[i-a]);
         
    //      if(i-b >=0) dp[i] = max(dp[i],dp[i-b]);
         
    //      if(i-c >=0) dp[i] = max(dp[i],dp[i-c]);
         
    //      if(dp[i]!=-1)
    //         dp[i]++;
    //  }
  
    // return dp[n];
       
       //********************************RECURSIVE********************************************************************
       if(n<0) return -1;
       if(n==0) return 0;
       int res = max
       (    {   maxCuts(n-a,a,b,c),
                maxCuts(n-b,a,b,c),
                maxCuts(n-c,a,b,c)
            }
        );
       if(res==-1) return res;
       else return res+1;
    } 


int main() {
    freopen("input.txt","r",stdin);
	
int t;cin>>t;
while(t--){
    int n,a,b,c; cin>>n>>a>>b>>c;
    cout<<maxCuts(n,a,b,c)<<"\n";
}

}