// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    //these lists are used to get row and column numbers of 8 
    //neighbours of a given cell.
    vector<int>dx = {-1,0,1,0,1,-1,-1,1};
    vector<int>dy = {0,-1,0,1,1,1,-1,-1};
    
    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 and x < n and y >=0 and y < m);
    }
    
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        //boolean array to mark visited cells.
        //initially all cells are unvisited.
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        
        //using queue for BFS.
        queue<pair<int, int>>q;
        int ans = 0;
        
        //traversing over all cells of given matrix.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if cell is unvisited and grid value is 1, we increment the 
                //count and mark it as visited.
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    ans++;
                    vis[i][j] = true;
                    
                    //pushing it into the queue.
                    q.push({i,j});
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int k = 0; k < 8; k++)
                        {
                            //if row and column number is in range, grid value 
                            //is 1 and cell is not yet visited,
                            if(
                                isValid(x+dx[k], y+dy[k],n,m) 
                                and 
                                !vis[x+dx[k]][y+dy[k]] 
                                and 
                                grid[x+dx[k]][y+dy[k]] == '1'
                                )
                            {   
                                //we push the cell in queue and mark it visited.
                                q.push({x + dx[k], y + dy[k]});
                                vis[x + dx[k]][y + dy[k]] = true;
                            }
                        }
                    }
                }
            }
        }
        //returning the result.
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
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends