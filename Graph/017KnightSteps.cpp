// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    private:
	struct cell{
		int x;
		int y;
		int steps;
	};
    public:
    
    //Function to check if cell indexes are within bounds.
	bool isValid(int x, int y, int N){
		return (x >=0 and x < N and y >=0 and y < N);
	}
	
	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
		KnightPos[0]--;
		KnightPos[1]--;
		TargetPos[0]--;
		TargetPos[1]--;
		
		//using boolean list to mark visited cells and currently 
        //marking all the cells as false.
		vector<vector<bool>>vis(N, vector<bool>(N, false));
		
		vector<vector<int>>dxy = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
		
		//queue for storing visited cells by knight in board and steps taken.
		queue<cell>q;
		
		//pushing starting position of knight with 0 distance.
		q.push({KnightPos[0], KnightPos[1], 0});
		
		//marking starting cell as visited.
		vis[KnightPos[0]][KnightPos[1]] = true;
		
		while(!q.empty())
		{
		    //storing cell indexes and steps of front element and popping them.
			int x = q.front().x;
			int y = q.front().y;
			int steps = q.front().steps;
			q.pop();
			
			//if we reach the required cell, we return true.
			if(x == TargetPos[0] and y == TargetPos[1])
				return steps;
				
			//using loop to reach all the cells that can be reached by knight.
			for(int i = 0; i < dxy.size(); i++)
			{
				int n_x = x + dxy[i][0];
				int n_y = y + dxy[i][1];
				
				//if cell indexes are valid and cell is not visited, we push the 
				//indexes in queue with steps and mark cell as visited.
				if(isValid(n_x, n_y, N) and !vis[n_x][n_y])
				{
					q.push({n_x, n_y, steps+1});
					vis[n_x][n_y] = true;
				}
			}
		}
		return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends