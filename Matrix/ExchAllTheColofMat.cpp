// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to reverse the columns of a matrix. 
    void reverseCol(vector<vector<int> > &matrix)
    {
        int n1 = matrix.size();
        int m1 = matrix[0].size();
        for(int i = 0; i < n1; i++)
            for(int j = 0; j < m1 / 2; j++)
            {
                //swapping the elements (element at 1st column with element
                //at last column, element at 2nd column with element at 
                //second last column and so on).
                swap(matrix[i][j], matrix[i][m1-j-1]);
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
        ob.reverseCol(matrix);

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
}
  // } Driver Code Ends