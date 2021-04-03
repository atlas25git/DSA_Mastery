// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
    public:
        // Function to insert heap
        double median;
        priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min;
    void insertHeap(int &x)
    {
        // insert in minheap or maxheap
    	if (max.empty()) 
    		max.push(x);
    	else if (x > max.top()) 
    		min.push(x);
    	else if(min.empty())
    	{
    		min.push(max.top());
    		max.pop();
    		max.push(x);
    	}
    	else
    		max.push(x);
    	balanceHeaps();
    }
    
    // Function to balance heaps
    void balanceHeaps()
    {
    	if (abs(max.size() - min.size()) > 1) //Heaps are not balanced
    	{
    		if (max.size() > min.size())
    		{
    			min.push(max.top());
    			max.pop();
    		}
    		
    		else
    		{
    			max.push(min.top());
    			min.pop();
    		}
    	}
    }
    
    // Function to return getMedian
    double getMedian()
    {
        // if total size is even
    	if ((max.size() + min.size()) % 2 == 0)
    	{
    		median = (max.top() + min.top());
    		median /= 2;
    	}
    	else // if total size is odd
    	{
    		if (min.empty())
    			median = max.top();
    		else if (min.size() < max.size())
    			median = max.top();
    		else
    			median = min.top();
    	}
    	
    	return median;
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  