// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
//Back-end complete function Template for C++

int n;
// A min heap node
struct MinHeapNode
{
	int element; // The element to be stored
	int i; // index of the array from which the element is taken
	int j; // index of the next element to be picked from array
};

// Prototype of a utility function to swap two min heap nodes
void swap(MinHeapNode *x, MinHeapNode *y);

// A class for Min Heap
class MinHeap
{
	MinHeapNode *harr; // pointer to array of elements in heap
	int heap_size; // size of min heap
public:
	// Constructor: creates a min heap of given size
	MinHeap(MinHeapNode a[], int size);

	// to heapify a subtree with root at given index
	void MinHeapify(int );

	// to get index of left child of node at index i
	int left(int i) { return (2*i + 1); }

	// to get index of right child of node at index i
	int right(int i) { return (2*i + 2); }

	// to get the root
	MinHeapNode getMin() { return harr[0]; }

	// to replace root with new node x and heapify() new root
	void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};

// This function takes an array of arrays as an argument and
// All arrays are assumed to be sorted. It merges them together
// and prints the final sorted output.
class Solution{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        n = k;
    	vector<int> output(n*k);// To store output array
    	// Create a min heap with k heap nodes. Every heap node
    	// has first element of an array
    	MinHeapNode *harr = new MinHeapNode[k];
    	for (int i = 0; i < k; i++)
    	{
    		harr[i].element = arr[i][0]; // Store the first element
    		harr[i].i = i; // index of array
    		harr[i].j = 1; // Index of next element to be stored from array
    	}
    	MinHeap hp(harr, k); // Create the heap
    
    	// Now one by one get the minimum element from min
    	// heap and replace it with next element of its array
    	for (int count = 0; count < n*k; count++)
    	{
    		// Get the minimum element and store it in output
    		MinHeapNode root = hp.getMin();
    		output[count] = root.element;
    
    		// Find the next elelement that will replace current
    		// root of heap. The next element belongs to same
    		// array as the current root.
    		if (root.j < n)
    		{
    			root.element = arr[root.i][root.j];
    			root.j += 1;
    		}
    		// If root was the last element of its array
    		else root.element = INT_MAX; //INT_MAX is for infinite
    
    		// Replace root with next element of array
    		hp.replaceMin(root);
    	}
    
    	return output;
    }
};

// FOLLOWING ARE IMPLEMENTATIONS OF STANDARD MIN HEAP METHODS
// FROM CORMEN BOOK
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1)/2;
	while (i >= 0)
	{
		MinHeapify(i);
		i--;
	}
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l].element < harr[i].element)
		smallest = l;
	if (r < heap_size && harr[r].element < harr[smallest].element)
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
	MinHeapNode temp = *x; *x = *y; *y = temp;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends