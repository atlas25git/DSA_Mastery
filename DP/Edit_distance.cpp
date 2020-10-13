// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



    int ed(string s, string t, int m,int n)
    {
    //2.Weiting the base cases induced from the rec. condn
    if(m==0)return n;//n charachters remaining would need to be inserted
    if(n==0)return m;//remaining char. would need to bve deleted
    
    //1.Writing the recursive base cases
    //when both the last char. match
    if( s[m-1] == t[n-1] ) return ed(s,t,m-1,n-1);
    
    //Case when it ain't the case
    //since we are gonna consider one of the operations (INSERT/DEL/REPLACE) 
    //we'll be counting one operation cost
    else 
        return 1+ min({
                        // remember s has to be converted into t
                        //Replace
                        ed(s,t,m-1,n-1),
                        //INSERT 
                        ed(s,t,m,n-1),
                        //DEL here the length of m will change due to del oprn  and n since last has been matched 
                        ed(s,t,m-1,n-1)
         } );
    }
    
    
	int editDistance(string s, string t)
		{
		    int ans=ed(s,t,s.size(),t.size());
		    return ans;
		    
		}

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    
    	int ans = editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends