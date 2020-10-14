#include<bits/stdc++.h>
using namespace std;


       
  int minCoins(int val,int a,int b,int c) 
    { 
        //***************************recursive**********************
    //   if(val==0)return 0;
    //   if(val<0)return 999999;
    //   int res=min({
    //                 minCoins(val-a,a,b,c),
    //                 minCoins(val-b,a,b,c),
    //                 minCoins(val-c,a,b,c)

    //                 });
    //     if(res>99999)return -2;
    //     else return res+1;
        
        //dp based

        int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<long long int > dp(amount + 1, INT_MAX);
		// Base Case
		dp[0] = 0;
		// Compute minimum coins required for all 
    	// values from 1 to amount 
		for(int  i = 1; i <= amount; i++)
			// Go through all coins smaller than i
			for(int j = 0; j < n and nums[j] <= i; j++)
				dp[i] = min(dp[i], 1LL + dp[i - nums[j]]);

		if(dp[amount] >= INT_MAX)
			return -1;
		return int(dp[amount]);
          
    }  


int main() {
	
int a=2,b=6,c=11, val =7;

cout<<minCoins(val,a,b,c);
	

}