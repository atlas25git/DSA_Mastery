//https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
 {   
     
// int dp[102][102];
//     int ed(string s, string t, int m, int n)
//     {
        //********************************RECURSIVE SOLLUTION**********************************************************************
    // //2.Weiting the base cases induced from the rec. condn
    // if(m==0)return n;//n charachters remaining would need to be inserted
    // if(n==0)return m;//remaining char. would need to bve deleted
    
    // //1.Writing the recursive base cases
    // //when both the last char. match
    // if( s[m-1] == t[n-1] ) return ed(s,t,m-1,n-1);
    
    // //Case when it ain't the case
    // //since we are gonna consider one of the operations (INSERT/DEL/REPLACE) 
    // //we'll be counting one operation cost
    // else 
    //     return 1+ min(
    //                     // remember s has to be converted into t
                        
    //                     //Replace
    //                     min(ed(s,t,m-1,n-1),
                        
    //                     //INSERT 
    //                     ed(s,t,m,n-1)   ),
                        
    //                     //DEL here the length of m will change due to del oprn  and n since last has been matched 
    //                     ed(s,t,m-1,n-1)
                        
    //                     );
    //****************************************************MEMOIZATION**************************************
      
//         if(m==0)return n;
//         if(n==0)return m;
//         int &ans=dp[m][n];
//         if(ans != -1)return ans;
        
//         if(s[m-1]==t[n-1]) return ans=ed(s,t,m-1,n-1);
//         else
//                   return  ans=1+ min(
//                         // remember s has to be converted into t
                        
//                       { //Replace
//                         ed(s,t,m-1,n),
                        
//                         //INSERT 
//                         ed(s,t,m,n-1)   ,
                        
//                         //DEL here the length of m will change due to del oprn  and n since last has been matched 
//                         ed(s,t,m-1,n-1)
                        
//                         });
    
    
//     }
    
    
// 	public:
// 		int editDistance(string s, string t)
// 		{   memset(dp,-1,sizeof(dp));
// 		    int ans=ed(s,t,s.size(),t.size());
// 		    return ans;
		    
// 		}
//*****************************************************TABULATION BASED*****************************************************
    int ed(string s,string t,int m,int n)
    {
         int dp[m+1][n+1];
         for(int i=0;i<=m;i++)dp[i][0]=i;
         for(int i=0;i<=n;i++)dp[0][i]=i;
         
         for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1];
            else 
                dp[i][j]=1 + min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            }
        } 
        return dp[m][n];
        
    }
		
	public:
		int editDistance(string s, string t)
		{   
		    int ans=ed(s,t,s.size(),t.size());
		    return ans;
		    
		}

     
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends