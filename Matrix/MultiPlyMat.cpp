// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        int r1 = A.size();
        int c1 = A[0].size();
        int r2 = B.size();
        int c2 = B[0].size();
        //cout<<"r1 "<<r1<<"::"<<"c1 "<<c1<<" ";
        //return A;
        //final dimensions: r1 x c2
        vector<vector<int>> result;
        
        if(c1==r2)//tho it is row into col multipl. but we're checking for
                //their corresponding lengths so that it is ensured
        {   result.resize(r1);
            for(int i=0;i<r1;i++)
            {   
                result[i].assign(c2,0);
                
                for(int j=0;j<c2;j++)
                {  
                    int res=0;
                  
                    for(int k=0;k<c1;k++)
                    {
                        res += A[i][k]*B[k][j];
                        //cout<<res<<" ";
                    }
                    
                    result[i][j]=res;
                }
            }
        }
    
    return result;
    
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
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.multiplyMatrix(A,B);

        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends