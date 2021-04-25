// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    
    
        void swap(int *xp, int *yp)
        {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
        }

//Function to do transpose of matrix.
    void transpose(vector<vector<int> >& matrix, int n) 
    { 
        for (int i = 0; i < n; i++) 
            for (int j = i; j < n; j++) 
                //swapping elements at (i,j) and (j,i).
                swap(&matrix[i][j], &matrix[j][i]); 
    } 

//after transposing we swap elements of each column (1st with last, 2nd with 
//second last) one by one for finding left rotation of matrix by 90 degree.
    void reverseColumns(vector<vector<int> >& matrix, int n) 
    { 
        for (int i = 0; i < n; i++) 
            for (int j = 0, k = n - 1; j < k; j++, k--)
                //swapping elements in each column.
                swap(&matrix[j][i], &matrix[k][i]); 
    } 
      
//Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    {
        transpose(matrix,n); 
        reverseColumns(matrix,n); 
    } 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends