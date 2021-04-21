// { Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
  void binSort(int A[], int N)
{
    int low = 0, high = N-1;
    
    //Using segregation method.
    while(low <=  high){
        
        //If element at left index is 0, we increase the left index.
        if(A[low] == 0){
            low++;
        }
        //Else If element at high index is 1, we decrease the right index.
        else if(A[high] == 1){
            high--;
        }
        //Else, we swap the elements at left and right index.
        else{
            int temp = A[low];
            A[low] = A[high];
            A[high] = temp;
            //Updating values of left and right index after swapping.
            low++;
            high--;
        }
    }
}
};

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}



  // } Driver Code Ends