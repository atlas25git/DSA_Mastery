// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



//Function to return sum of upper and lower triangles of a matrix.
int* sumTriangles(int n, int matrix[][n])
{
    int upper = 0; 
    int lower = 0;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            //diagonal elements will be common in both upper and lower sum.
            if(i == j)
            {
                upper += matrix[i][j];
                lower += matrix[i][j];
            }
            
            //else if j>i, this condition satisfies only for upper triangle.
            else if (j>i) 
                upper += matrix[i][j]; 

            //else if i>j, this condition satisfies only for lower triangle.
            else if(j<i)
                lower += matrix[i][j]; 
        }
    }
    //storing both the sum in a list and returning the list.
    static int result[2];
    result[0] = upper;
    result[1] = lower;
    return result; 
}


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
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends