// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to interchange the rows of a matrix.
    void interchangeRows(vector<vector<int> > &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        // for(int i = 0; i < n1/2; i++)
        // {
        //     //swapping the elements (element at 1st row with element
        //     //at last row, element at 2nd row with element at 
        //     //second last row and so on).
        //     swap(matrix[i], matrix[n1-i-1]);
        // }
        
        for(int j=0;j<col;j++)
        {
            for(int i=0;i<row/2;i++)
            {
                swap(matrix[i][j],matrix[row-1-i][j]);
            }
        }
        
        
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.interchangeRows(matrix);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends