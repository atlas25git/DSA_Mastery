// Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

// Input:
// The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

// Output:
// For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

// Constraints:
// 1 <= T <= 200
// 1 <= n <= 104
// 1 <= a[i] <= 104

// Example:
// Input:
// 2
// 6
// 5 5 10 100 10 5
// 3
// 1 2 3
// Output:
// 110
// 4

// Explanation:
// Testcase1:
// 5+100+5=110
// Testcase2:
// 1+3=4

#include <bits/stdc++.h>

using namespace std;

int sum(int arr[],int n);
int sumdp(int * arr,int n);
int sumdpO1s(int * arr,int n);

int main() {
    // freopen("input.txt","r",stdin);
	
	int t; cin>>t;
	while(t--){
	    
	    int n;cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];   
	    }
	    
	    cout<<sumdpO1s(arr,n)<<"\n";
	    //cout<<n<<"\n";
	}
	
	return 0;
	
}

int sum(int arr[],int n)
    {
        if(n==1) return arr[0];
        else if(n==2) return max(arr[0],arr[1]);
        
        else 
        return max(sum(arr,n-1),
                   sum(arr,n-2) + arr[n-1]
                   );
        
    }

//########################################DP#################################################

int sumdp(int * arr,int n){
    
    //Explanation
    // {10,5,15,20}
    // dp[] =   | 10 | 10 | 25 | 
    // index   0   1    2    3    4  
    
    // dp[1]=arr[0];
    // dp[i] stores the result for an array of length i.
    // dp[3]=max(dp[2],dp[1] + arr[2])
    // dp[4]=max(dp[3],dp[2]+arr[3])
    
    int dp[n+1];
    if(n==1)return arr[0];
    dp[1] =arr[0];
    dp[2]=max(arr[0],arr[1]);
    //because it is a base case. if we exclude last value from array of length 2 it'd be 
    //first one or last one
    
    for(int i=3;i<=n;i++)
        dp[i]=max(dp[i-1],dp[i-2] + arr[i-1]);
    return dp[n];
}

int sumdpO1s(int * arr,int n){
    

    
    if(n==1)return arr[0];
    int prev_prev =arr[0];
    int prev=max(arr[0],arr[1]);
    int res = prev;

    
    for(int i=3;i<=n;i++)
    {   res=max(prev,prev_prev + arr[i-1]);
        prev_prev=prev;
        prev = res;
     }
return res;
}




