// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution 
{
    public:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        //checking whether the cell is within the matrix bounds.
        if(x<0||y<0||x>=grid.size()||grid[x].size()<=y){
            return ;
        }
        //if grid value is X, we update the grid value as 0 and
        //call the function recursively for adjacent nodes.
    	if(grid[x][y]=='X')
    	{
    		grid[x][y]='O';
    		dfs(grid,x+1,y);dfs(grid,x,y+1);dfs(grid,x-1,y);dfs(grid,x,y-1);
    	}
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
    	int n=grid.size();
    	int m=grid[0].size();
        int i,j,ans=0;
        
        //traversing all the cells of the matrix.
    	for(i=0;i<grid.size();i++)
    	{
    		for(j=0;j<grid[i].size();j++)
    		{   
    		    //the question requires us to ans wether we could 
    		    //give all the disconnected components of given
    		    //graph
    		    //if grid value is X, we increment the counter and
                //call the dfs function.
    			if(grid[i][j]=='X'){
    				ans++;
    				dfs(grid, i,j);
    			}
    		}
    	}
    	//returning the count.
    	return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends