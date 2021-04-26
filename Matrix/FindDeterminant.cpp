// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends





class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int det(vector<vector<int> > B, int n, int m)
    {
    
        int row_size = m;
        int column_size = n;

        if (row_size != column_size) {
    //printf("DimensionError: Operation Not Permitted \n");
            return -1;
        }

    //base cases
        else if (row_size == 1)
            return (B[0][0]);

        else if (row_size == 2)
            return (B[0][0]*B[1][1] - B[1][0]*B[0][1]);

        else 
        {
            int minor[row_size-1][column_size-1];
            int row_minor, column_minor;
            int firstrow_columnindex;
            int sum = 0;

            register int row,column;

            //excluding first row and current column.
            for(firstrow_columnindex = 0; firstrow_columnindex < row_size; firstrow_columnindex++) 
            {
                row_minor = 0;
    
                for(row = 1; row < row_size; row++)
                {//computation will always start with row 1
                    column_minor = 0;
    
                    for(column = 0; column < column_size; column++) 
                    {
                        if (column == firstrow_columnindex)
                            continue;
                        else
                            minor[row_minor][column_minor] = B[row][column];
    
                        column_minor++;
                    }
    
                    row_minor++;
                }
    
                m = row_minor;
                n = column_minor;
                
                //adding or subtracting the value of (B[0][i])*Cofactor alternately.
                if (firstrow_columnindex % 2 == 0)
                    sum += B[0][firstrow_columnindex] * det(m, n, minor);
                else
                    sum -= B[0][firstrow_columnindex] * det(m, n, minor);

            }
            //returning the determinant.
            return sum;
        }
    }

//Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        return det(matrix,n,n);
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
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}  // } Driver Code Ends