//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
#include <bits/stdc++.h>

using namespace std;

int kp(int n,int wt,int wta[],int nv[] ){
//     //*************************************************recursive sol**************************************
//     //step 3 writing base cases
//     if(n==0 || wt==0)return 0;
    
     
//   //case 1, where the last item coudn't be considered due to it's value
//   if(wt<wta[n-1])return kp(n-1,wt,wta,nv);
//   //case 2 ,when the last item could be considered but we try both the cases of considering it and not considering it.
//   else 
//         return max(kp(n-1,wt,wta,nv), nv[n-1]+kp(n-1,wt-wta[n-1],wta,nv));
        
    //*********************************************tabulation based **************************************
    //since there are 2 changing values, we will be making a 2d array
    int dp[n+1][wt+1];
    //i'th col. belongs to no. of itmes that we are considerimg according to the given array,
    //j'th col is the one wher we calculate items and value (max) for wt's on the stepsof 1.
    //base case intialization
    
    for(int i=0;i<=wt;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=wt;j++)
        {   //since j represents the wt limit we have, there fore we will consider the cases wher
            //the value of items is feasible, if it is greater than the total weight we will simply,
            //fill in the value with max. val for the wt-1;
            if(wta[i-1]>j)dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(nv[i-1]//accessing the value at i'th position in given array
                        + dp[i-1][j-wta[i-1]]//this the case where we are adding the value of considered item,
                        //and now we access the value with i-1, items and for wt that is the current wt value(j)
                        //- the considered wt.
                        ,dp[i-1][j]//this is the case where we do not consider the last item
                            );
            
        }
    }
    return dp[n][wt];
}

int main() {
	// freopen("input.txt","r",stdin);
	int t;cin>>t;
	while(t--){
	    int n,wt;
	   
	    cin>>n>>wt;
	    
	    int w[wt],v[n];
	    
	    for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<wt;i++)cin>>w[i];
        
        cout<<kp(n,wt,w,v)<<"\n";
	}
}