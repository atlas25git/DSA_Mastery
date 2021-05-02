// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to find nth number made of only prime digits.
    int primeDigits(int n)
    {
    	n--;
    	int ans[1000]={0};
    	
    	//list to store numbers made of only prime digits.
    	memset(ans,0,sizeof(ans));
    	
    	int i, j, digits=0, Count=0, k=0, a[4]={2,3,5,7};
        
        //storing the values for first four prime numbers in the list.
        ans[0]=2;
        ans[1]=3;
        ans[2]=5;
        ans[3]=7;
        k=4;
        
        //we start traversing from 22.
        for(i=22; i<2300; i++)
        {
            int p=i;
            digits=0;
            Count=0;
            
            //while current index is not 0, we run a loop.
            while(p)
            {
                digits++;
                int r=p%10;//checks the ones place 
                p=p/10;    //reduces the no to eliminate the current ones
                
                //checking if each digit in current index p is prime or not.
                for(j=0;j<4;j++)
                {
                    if(r==a[j])
                    {
                        Count++;
                        break;
                    }
                }
            }
            
            //if all the digits are prime then storing the number in list.
            if(Count==digits)
                ans[k++]=i;
            else
                continue;
        }
        //returning the nth element from the list.
    	return ans[n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    // All the above tasks are preprocessing, now you can run testcases
    // and then print the values accordingly
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout << ob.primeDigits(n) << "\n";   
    }
}
  // } Driver Code Ends