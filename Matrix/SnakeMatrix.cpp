// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:

    vector<int> snakePattern(vector<vector<int>> matrix)
{   
    int n=matrix.size();
    vector<int> output;
    output.resize(n*n);
    //int *output = malloc(sizeof(int) * (n * n));
    int pos = 0;
    
    //traversing over the rows.
    for (int i = 0; i < n; i++) 
    {
        //if current row is even, we add the elements 
        //in the list from left to right.
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
                output[pos++] = matrix[i][j];
        }
        //else current row is odd and we add the elements 
        //in the list from right to left.
        else 
        {
            for (int j = n - 1; j >= 0; j--)
                output[pos++] = matrix[i][j];
        }
    }
    //returning the list.
    return output;
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
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends