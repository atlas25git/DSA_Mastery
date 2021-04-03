// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    void swap(int *a,int *b)
    {
    	int c=*a;
    	*a=*b;
    	*b=c;
    }
    
    public:
    void heapify(int arr[], int n, int i)  {
        int l=i*2+1;
    	int r=i*2+2;
    	int largest=i;
    	if(l<n && arr[largest]<arr[l]) // if value at largest is larger change largest
    		largest=l;
    	if(r<n && arr[largest]<arr[r]) // if value at largest is larger change largest
    		largest=r;
    	if(largest!=i) // if largest is not same as initial value, only then
    	{
    		swap(&arr[i],&arr[largest]);
    		heapify(arr,n,largest); // recusrsively call Maxheapify for largest variable
    	}
    }
    
    public:
    // Rearranges input array so that it becomes a min heap
    void buildHeap(int arr[], int n)  { 
    	for(int i=n/2-1;i>=0;i--)
    	   heapify(arr,n,i); // calling heapify for values from half to first index
    }
    
    public:
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int i=n-1; i>=0; i--)
        {   //swapping step is like the one that we did in selection sort
            //we select the maximum element that is at a[0], with last, 
            //so as to fix its position
            //thereafter we call heapify on the reduced array, i.e,
            //with the index of the swapped node
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
    }
}; 




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends