https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
#include <bits/stdc++.h>
#include <string.h>
#include <limits.h>
using namespace std;


       
  int minJumps(int arr[], int n) 
    { 
        // *****************************************recursive*****************************************************
        // if(n==1)return 0; //base case made on the basis of size n=1, index=0;
       
       
        // int res=INT_MAX;
        
        // Recursive fn. made on the backward iteration basis, we are considering from backwards, that
        // every i+arr[i]>=n-1, we take the case and recursively iterate the problem for min steps 
        // to reach till i
        
        // for(int i=0;i<=n-2;i++)
        // {
        //     if(arr[i]+1>=n-1)
        //     {    int sub_res=minJumps(arr,i+1);
            
        //         if(sub_res!=INT_MAX)
        //         res=min(res,sub_res+1);
        //     }    
                
        //     } 
        // return res;
        
        // *****************************************tabulation*****************************************************
        int dp[n]; 
        int i, j; 
      
       
        dp[0] = 0; 
      
        
        for (i = 1; i < n; i++) { 
            dp[i] = INT_MAX; 
            for (j = 0; j < i; j++)
            { 
                if (i <= j + arr[j])//checking from dis. array
                { if(dp[j] != INT_MAX)
                //checking if the sub problem in case,j, has any solution
                //or not
                //the foollowing step us to determine the index from where 
                //the i'th index is reachable
                //in min. steps, so we compare for all preceeding values of i
                //what is the min. steps possible.
                        {dp[i] = min(dp[i], dp[j] + 1); 
                        break;} 
                } 
            } 
        } 
        return dp[n - 1]; 
    } 
    

int main() {
	
int arr[] = {3, 4, 2, 1, 2, 1}, n =6;

cout<<minJumps(arr, n);
	

}