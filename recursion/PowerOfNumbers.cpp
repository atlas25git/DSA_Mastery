// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

 // } Driver Code Ends

class Solution{
    public:
    // compute pow(n, R) with mod 1000000007
    
    long long modfun(long long n, long long R)
    {
        // Base cases 
        if (n == 0) 
            return 0; 
        // power zero mean answer is 1
        if (R == 0)  
            return 1; 
      
        long long y; 
        // If R is even 
        if (R % 2 == 0) { 
            
            //finding r/2 power as power is even then storing answer in y
            //and if power is even like 2^4 we can simply do (2^2)*(2^2)
            
            y = modfun(n, R/2);  
            y = (y%mod * y%mod) % mod; 
        } 
      
        // If R is odd 
        else { 
            y = n % mod;
            
            // reduce the power by 1 to make it even.
            // The reducing power by one can be done if we take one n out. 
            // Like 2^3 can be written as 2*(2^2)
            
            y = (y%mod * modfun(n, R - 1)%mod) % mod; 
            
        } 
        // finally return the answer (y+mod)%mod = (y%mod+mod%mod)%mod = (y%mod)%mod
        return (y);  
    }
    
    
    long long power(int N,int R)
    {
        return modfun(N,R)%mod;
        
    }

};

// { Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}  // } Driver Code Ends