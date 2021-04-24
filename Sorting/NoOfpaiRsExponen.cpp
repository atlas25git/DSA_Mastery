// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    int count(int x, int Y[], int N, int NoOfY[])
    {
        
        //If x is 0, then there can't be any value in Y[]
        //such that x^Y[val]>Y[val]^x. 
        if (x == 0) return 0;
        
        //If x is 1, then number of pair is equal to number of zeroes in Y[].
        if (x == 1) return NoOfY[0];
        
        
        //Finding number of elements in Y[] with value greater than x.
        int* idx = upper_bound(Y, Y + N, x);
        
        //Updating number of pairs.
        int ans = (Y + N) - idx;
        
        //If we have reached here, then x must be greater than 1. 
        //it's the case when x>1 but smaller than y in this case 
        //we're reducing our intial supposition
        //Increasing number of pairs for y=0 and y=1.
        ans += (NoOfY[0] + NoOfY[1]);
        
        //Decreasing number of pairs for exception where x=2 and (y=4 or y=3). 
        if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]);
        
        //Increasing number of pairs for exception where x=3 and y=2.
        if (x == 3)  ans += NoOfY[2];
     
        //returning number of pairs.
        return ans;
    }
    
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
        //Array to store counts of 0, 1, 2, 3 and 4 present in array Y.
        int NoOfY[5] = {0};
        //Storing the count in array if Y[i]<5.
        for (int i = 0; i < N; i++)
            if (Y[i] < 5)
                NoOfY[Y[i]]++;
     
        //Sorting Y[] so that we can do binary search on it later on.
        sort(Y, Y + N);
     
        long long total_pairs = 0; 
        
        //Taking every element of X[] and counting pairs with it.
        for (int i=0; i<M; i++)
            total_pairs += count(X[i], Y, N, NoOfY);
            
        //returning number of pairs.
        return total_pairs;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends