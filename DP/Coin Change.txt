//https://practice.geeksforgeeks.org/problems/coin-change2448/1
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
    // Recursive solution
    
    //   if(n==0)return 1; // //cause there's a way for 0 sum, not selecting any coin :P
    //   if(m==0)return 0;
    // //case when not considering the last one.   
    //     long long int res=count(S,m-1,n);
    // //case when considering the particular case 
    //     if(S[m-1]<=n)
    //          res=res+count(S,m,n-S[m-1]);
            
    // return res;
    
    long long int dp[n+1][m+1];
    for(long long int j=0;j<m+1;j++)dp[0][j]=1;
    for(long long int i=1;i<n+1;i++)dp[i][0]=0;
    
    for(long long int i=1;i<n+1;i++){
        for(long long int j=1;j<m+1;j++){
            dp[i][j]=dp[i][j-1]; 
            
            //For any given sum and array, when we are inncreasing the array elements, the combinations
            //would comprise of the previoously existing combinations.  
            
            if(S[j-1]<=i)
            //Here considering if the current coin value is less than the sum ,it could be included, and for the combination
            //we're looking for the available combinations with the sum minus selected coin value 
            //and the combinations ofr thus the resulting valuye of n
            dp[i][j] += dp[i-S[j-1]][j];
        }
    }
    return dp[n][m];
    }