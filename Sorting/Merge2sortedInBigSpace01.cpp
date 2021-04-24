// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


class Solution{

    public:
    //Function to find next gap.
    int nextGap(int gap) 
    { 
        //It returns the ceil value of gap/2 or 0 if gap is 1.
    	if (gap <= 1) 
    		return 0; 
    	return (gap / 2) + (gap % 2); 
    } 
    
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    { 
    	int i, j, gap = n + m; 
    	
    	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    	{ 
    	    //ARRAY1 
    		for (i = 0; i + gap < n; i++) 
    			if (arr1[i] > arr1[i + gap]) 
    			swap(arr1[i], arr1[i + gap]); 
    
    		//ARRAY1 & ARRAY2
    		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++)
    			if (arr1[i] > arr2[j]) 
    			swap(arr1[i], arr2[j]); 
            
            
            //ARRAY2
    		if (j < m) 
    		{ 
    			for (j = 0; j + gap < m; j++) 
    				if (arr2[j] > arr2[j + gap]) 
    				swap(arr2[j], arr2[j + gap]); 
    		} 
    	} 
    } 
};


// { Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // } Driver Code Ends