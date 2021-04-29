// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int sizeOfArray, int sum);

 // } Driver Code Ends
//User function Template for C++

//Function to check if two numbers in the array have sum equal to the given sum.
int sumExists(int arr[], int N, int sum)
{
    //using set to store the elements.
    unordered_set<int> s; 
 
    //iterating over the array.
    for(int i=0;i<N;i++) 
    {
      int temp=sum-arr[i]; 
      //if (sum-arr[i]) or temp exists in set, we return 1.
      if(temp>=0 && s.count(temp)!=0) 
      return 1; 
      
      //inserting current element in the set.
      s.insert(arr[i]); 
    }
    
//if no such pair is present, we return 0.
return 0;
}

// { Driver Code Starts.

int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0;i<N;i++)
        cin>>arr[i];
        int sum;
        cin>>sum;
        
        cout<<sumExists(arr,N,sum)<<endl;
        
        
    }
    
    
    
	return 0;
}  // } Driver Code Ends