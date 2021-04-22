// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int findTriplets(int arr[], int n){
        
        //Sorting the elements.
        mergeSort(arr, 0, n-1);
        
        //Traversing the array elements.
        for (int i=0; i<n-2; i++)
        {
            //Taking two pointers. One at element after ith index and another
            //at the last index.
            int l = i + 1;
            int r = n - 1;
            int x = arr[i];
            
            //Using two pointers over the array which helps in checking if
            //the triplet sum is zero.
            while (l < r)
            {
                //If sum of elements at indexes i, l and r is 0, we return true.
                if (x + arr[l] + arr[r] == 0)
                {
    				return 1;
                }
                //Else if the sum is less than 0, it means we need to increase the
                //sum so we increase the left pointer l.
                else if (x + arr[l] + arr[r] < 0)
                {
                    l++;
                }
                //Else the sum is more than 0 and we need to decrease the
                //sum so we decrease the right pointer r.
                else
                {
                    r--;
                }
            }
        }
            //returning false if no triplet with zero sum is present.
            return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends