// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to insert elements of arr in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
    {
        vector<vector<int>> hashTable(hashSize);
        //iterating over the array
        for(int i=0;i<sizeOfArray;i++)
        {
           //pushing element arr[i] in the vector hashTable
            //at position arr[i]%hashSize.
           hashTable[arr[i]%hashSize].push_back(arr[i]);
        }
        
        //returning the hashTable.
        return hashTable;
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
	    
	    
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution obj;
	    vector<vector<int>> hashTable;
	    hashTable = obj.separateChaining( hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashTable.size();i++)
	    {
	        if(hashTable[i].size()>0)
	        {
	            cout<<i<<"->";
	            for(int j=0;j<hashTable[i].size()-1;j++)
	            {
	                cout<<hashTable[i][j]<<"->";
	            }
	            cout<<hashTable[i][hashTable[i].size()-1];
	            cout<<endl;
	        }
	    }
	    
	    
	    
	}
	return 0;
};
  // } Driver Code Ends