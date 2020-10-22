// Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// For more description on this problem see wiki page

// Input:
// The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

// Output:
// For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

// Constraints:
// 1<=T<=30
// 1<=N<=10
// 1<=K<=50

// Example:
// Input:
// 2
// 2 10
// 3 5

// Output:
// 4
// 3

#include <bits/stdc++.h>
using namespace std;
//********************************************RECURSIVE****************************************************************
int flr(int k,int n)
{
    //Here notice the fact that we are asked for the min attempts for the worst case
    //of finding out the threshold floor.
    //Step 2> Base cases:
    if(k>1 && n==1)return k;//We aren't considering the case of 0 eggs because just at when the 
                          //egg count is to be reduced by ,the base case will be hit, and would return rem. k
    if(k==1 && n>=1) return 1;//if just one floor is left ,then all we need is one trial
    if(k==0 && n>=1) return 0;
    
    //  if (k == 1 || k == 0) 
    //     return k; 
    // if (n == 1) 
    //     return k; 
    
    //Here we are iteratively try for all the k floors and out of them will choose the min. no of trials required
    //for a worst case scenario
    //It is like we are dropping from say nth floor, and we iterate all of the k floors to find
    //this optimized nth floor
    int res=9999;
    for(int i=1;i<=k;i++)
    {
     int sub_res=max(
        //1. Egg Breaks 
            flr(i-1,n-1),
        //2. Doesn't Breaks
            flr(k-i,n)
                    );
        res=min(res,sub_res);
        
    }
    return res +1;
}
//***********************************************************DP******************************************************
int flrdp(int f,int e)
    {
        //since 2 dimensions are changing in the rec. call, therefore 2 dimension dp table
        //we will need f+1, for f values which ranges from 0,f,
        //and since e ranges from 1 to e, using e elements could suffice but for the sake of 
        //using it with index no, not by -1, we do this
        
      int  dp[f+1][e+1]; int res;
        
        // **********dp-table**************
        //   0 1 2 3  1.Since we are using the egg col index-1 we ill ignore for e=0, 
        // 0 #|0|0|0    as it is also not defined by our base case.
        // 1 #|1|1|1
        // 2 #|2| |
        // 3 #|3| |
        // 4 #|4| |
        // 5 #|5| |
        
    for(int i=1;i<=e;i++)
    {
        dp[0][i]=0;
        dp[1][i]=1;
    }
    
    for(int i=2;i<=f;i++)
        dp[i][1]=i;
    
    for(int i=2;i<=f;i++)
    {
        for(int j=2;j<=e;j++)
        {
            dp[i][j]= INT_MAX;
            for(int x =1;x<=i;x++)
            {
                // dp[i][j]= min(dp[i][j],
                //             1+max(dp[i-1][j-1],
                //             dp[i-x][j])
                //             );
                
                res = 1 + max( 
                              dp[i-1][j-1], 
                              dp[i-x][j]); 
                if (res < dp[i][j]) 
                    dp[i][j] = res;
                
                // res = 1 + max( 
                //               dp[i - 1][x - 1], 
                //               dp[i][j - x]); 
                // if (res < dp[i][j]) 
                //     dp[i][j] = res;
                
                // int r = 1+max(dp[i-1][j-1],
                //             dp[i-x][j]);
                // if(dp[i][j]< r) dp[i][j]=r;
                
            }    
        }
    }
    return dp[f][e];
    }



int res(int n, int f) 
{ 
   
    int dp[n + 1][f + 1]; 
    int res; 
   
  
   
    for (int i = 1; i <= n; i++) { 
        dp[i][1] = 1; 
        dp[i][0] = 0; 
    } 
  
   
    for (int j = 1; j <= f; j++) 
        dp[1][j] = j; 
  
    
    for (int i = 2; i <= n; i++) { 
        for (int j = 2; j <= f; j++) { 
            dp[i][j] = INT_MAX; 
            for (int x = 1; x <= j; x++) { 
                res = 1 + max( 
                              dp[i - 1][x - 1], 
                              dp[i][j - x]); 
                if (res < dp[i][j]) 
                    dp[i][j] = res; 
            } 
        } 
    } 
  
    
    return dp[n][f]; 
} 


int main() {
    freopen("input.txt","r",stdin);
	int t;cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    cout<<flrdp(k,n)<<"\n";
	}
	return 1;
}