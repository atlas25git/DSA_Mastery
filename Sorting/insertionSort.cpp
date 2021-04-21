// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int i)
{
      int key = arr[i];
      int j = i-1;

       //We run a loop from j and keep shifting the array elements
       //towards right till the element at jth index is greater
       //than element at ith index(key).
       while (j >= 0 && arr[j] > key)
       //at this step the key is placed at the position where no previous to it
       //is smaller than it.
       //such element once found is copied to one positon ahead,
       //and in the original position array element is placed.
       {
           //Shifting of array elements.
           arr[j+1] = arr[j];
           j = j-1;
           //at this stage j+1 and j both contain the same element
           // that is arr[j]
           //hence at last arr[j+1] is replaced with key
       }
       //Then we just insert the current element(key) at (j+1)th index.
       arr[j+1] = key;
}
//Function to sort the array in ascending order using insertion sort algorithm. 
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      //Calling of insert function.
      insert(arr, i);
}
};

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends