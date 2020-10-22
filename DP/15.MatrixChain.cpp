/* A naive recursive implementation that simply 
follows the above optimal substructure property */
#include <bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 
int MatrixChainOrder(int p[], int i, int j) 
{ 
	if (i == j) 
		return 0; 
	int k; 
	int min1 = INT_MAX; 
	int count; 

	// place parenthesis at different places 
	// between first and last matrix, recursively 
	// calculate count of multiplications for 
	// each parenthesis placement and return the 
	// minimum count 
	for (k = i; k < j; k++) { 
		count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j]; 
        // here the middle element will be k , hence for this step
        //the no. of multiplications will be i x k x j
        //in the subsequent rec. calls we are again calling in for min. in that 
        //part of array

		if (count < min1) 
			min1 = count; 
	} 

	// Return minimum count 
	return min1; 
} 
//****************************************************************DP*************************************************
int mcrdp(int arr[], int n)
{
    //     0 1 2 3 4    Here we only need the values marked with * to compute the final ans.
    //   0 #|0|*|*|*    Since j is the end index, therefore i will always be smaller than j
    //   1 #|#|0| |*    Hence we can disregard all such values from our table.
    //   2 #|#|#|0|*    # sign shows the disregarded columns
    //   3 #|#|#|#|0    filling in the base cases i+1=j case
    //   4 #|#|#|#|#

    int dp[n][n];

    for(int i=0;i<n-1;i++)dp[i][i+1]=0; //Here filling in till n-2, cause n-1+(1)=n, which is not available as a valid index

    for(int gap =2;gap<n;gap++)
    {
        for(int i=0;i+gap<n;i++)
        {
            int j=i+gap;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                dp[i][j]= min(dp[i][j], dp[i][k]+ dp[k][j]+ arr[i]*arr[k]*arr[j]);
            }

        }
    }
    return dp[0][n-1];

}

// Driver Code 
int main() 
{ 
	int arr[] = {40, 20, 30, 10, 30}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Minimum number of multiplications is "
		<< MatrixChainOrder(arr, 1, n - 1);

    cout << "Minimum number of multiplications using dp "
		<< mcrdp(arr,n); 
}