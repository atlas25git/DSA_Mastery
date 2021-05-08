// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	vector<int>dx = {1,-1,0,0};
	vector<int>dy = {0,0,1,-1};
	
	//Function to check whether the cell is within the matrix bounds.
	bool isValid(int x, int y, int n, int m){
		return (x >=0 and x < n and y >=0 and y < m);
	}
	
	//Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		
		//queue to store the cell indexes which have grid value 1.
		queue<pair<int, int>>q;
		
		//using dp list which will store the output.
		vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
		
		//traversing all the cells of the matrix.
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
			    //if grid value is 1, we update the dp value at same cell as 0 
			    //and push the cell indexes into queue.
				if(grid[i][j] == 1){
					dp[i][j] = 0;
					q.push({i,j});
				}
			}
		}
		
		while(!q.empty())
		{
		    //storing the cell indexes at top of queue and popping them.
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			//iterating over the adjacent cells.
			for(int i = 0; i < 4; i++)
			{
				int n_x = x + dx[i];
				int n_y = y + dy[i];
				if(isValid(n_x, n_y, n, m) and dp[n_x][n_y] > dp[x][y] + 1)//+1 coz moved dis 1
				{
				    //updating dp and pushing cell indexes in queue.
					dp[n_x][n_y] = dp[x][y] + 1;
					q.push({n_x, n_y});
				}
			}
		}
		//returning the dp list.
		return dp;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends