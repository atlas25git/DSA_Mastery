// Unique BST's 
// Medium Accuracy: 50.0% Submissions: 18490 Points: 4
// Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

// Input:
// First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

// Ouput:
// For each testcase, in a new line, print the answer.

// Constraints:
// 1<=T<=15
// 1<=N<=11

// Example:
// Input:
// 2
// 2
// 3
// Output:
// 2
// 5

// Explanation:

// Testcase1:
// for N = 2, there are 2 unique BSTs
//      1               2  
//       \            /
//       2         1

// Testcase2:
// for N = 3, there are 5 possible BSTs
//   1              3        3         2      1
//     \           /        /           /    \      \
//      3        2         1        1    3      2
//     /       /                \                      \
//   2      1               2                        3
#include <bits/stdc++.h>
using namespace std;
 
int dist(int n);

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    
	    int n; cin>>n;
	    cout<<dist(n)<<"\n";
	    
	}
	
	return 0;
}

int dist(int n){
    
    //we're here using the formula : res(n)= res(0)*rs(n-1) + res(1)*res(n-2) + ....... res(n-1)res(0)
    //here res(i)*res(n-i) represent the total no. of nodes on each sides of i+1th smallest key
    
    int dp[n+1];
    dp[0]=1;
    
    for(int i=1;i<=n;i++)
    {   ///wrote this formula by deducing it from the expression , res(3)=res(0)res(2) + res(1)res(1) +res(2)res(0)
        dp[i]=0;
        for(int j=0;j<i;j++)
            dp[i] += dp[j]*dp[i-j-1];
    }
    return dp[n];
}

//this can also be solved using a direct formula of catalan number , that is res(n)= 1/n+1 2nCn 