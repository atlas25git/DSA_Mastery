// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Consider each cell as a node and each boundary between any two adjacent cells be an edge, so total number of Node is N*N.

// 1. Create an empty Graph having N*N node.
// 2. push all node into graph.
// 3. Note down source and sink vertex
// 4. Now Appling BFS or DFS to find is there is path between to vertex or not in graph
//         If path is found return 1
//         else return 0

 

class Solution 
{
    public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};  
    
    //Function to check whether the cell is within the matrix bounds.
    bool isValid(int x, int y, int n, int m){
        return (x >= 0 and x < n and y >=0 and y < m);
    }
    
    //Function to find whether a path exists from the source to destination. 
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        //creating BFS queue 
        queue<pair<int, int>>q;
        
        //traversing all the cells of the matrix.
        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        	    //if there exists a cell in the matrix such that its 
                //value is 1 then we push it to queue.
        		if(grid[i][j] == 1){
        			q.push({i,j});
        		}
        	}
        }
        
        while(!q.empty())
        {
        	int x = q.front().first;
        	int y = q.front().second;
        	q.pop();
        	for(int i = 0; i < 4; i++)
        	{
        		int n_x = x + dx[i];
        		int n_y = y + dy[i];
        		
        		//if the cell is within matrix bounds.
        		if(isValid(n_x, n_y, n, m))
        		{
        		    //if the value of current cell is 2, we return true.
        			if(grid[n_x][n_y] == 2)
        				return true;
        				
        			//if the value of current cell is 3, we replace the value
        			//with 1 and push the cell into the queue.
        			if(grid[n_x][n_y] == 3){
        				grid[n_x][n_y] = 1;
        				q.push({n_x, n_y});
        			}
        		}
        	}
        }
        return false;

    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends