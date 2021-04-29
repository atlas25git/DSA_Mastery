// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int> &hash, int hashSize,int arr[],int N)
    {
        //storing -1 at all indexes in the hash table.
        for(int i=0;i<hashSize;i++)
    	    hash[i] = -1;
    	    
        //iterating over the array.
        for(int i=0;i<N;i++)
        {
            //if the value of hash table at index (arr[i]%hashSize) is -1 
            //which means empty then, we insert arr[i] at that place.
            if(hash[arr[i]%hashSize]==-1) 
            {
                hash[arr[i]%hashSize]=arr[i];
            }
            //else we quadratically traverse the array from the filled position 
            //to find an index with -1 in hash table.
            else
            {
                int k=arr[i]%hashSize; 
                int power=1;
                
                //using a loop which runs until we find an index with -1
                //in hash table which means empty.
                while(hash[(k+power*power)%hashSize]!=-1)
                {
                     power++;
                }
                //inserting arr[i] after finding the empty position.
                hash[(k+power*power)%hashSize]=arr[i]; 
            }
        }
    }

};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}


  // } Driver Code Ends