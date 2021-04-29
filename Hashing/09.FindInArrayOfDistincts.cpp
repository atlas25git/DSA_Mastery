// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int sumExists(int arr[], int N, int sum);

 // } Driver Code Ends
//User function Template for C++


//You need to complete this function.
//Function to check if there is a pair with the given sum in the array.
int sumExists(int arr[], int N, int sum)
{
    //using set to store the elements.
    unordered_set<int> s; 
    
    //inserting all elements in the set.
    for(int i = 0; i < N; i++)
         s.insert(arr[i]);
     
    //iterating over the array.
    for(int i=0;i<N;i++)
    {
       //taking care of cases like 4-2=2 as two 2's cannot exist in distinct
       //array so we continue iteration over next element.
       if(sum-arr[i]==arr[i]) 
          continue;
       else
          {
              //if (sum-arr[i]) exists in set, we return 1.
              if(s.count(sum-arr[i])!=0) 
              {
                return 1;
              }
          }
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
}
  // } Driver Code Ends