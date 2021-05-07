// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	int bfs(vector<int> adj[], int V, int vis[], int level[], int X) 
	{
        if(X>=V)
            return -1;
            
        //storing 0 or first vertex in x.
        int x = 0;
        
        //creating a queue and pushing x into it.
        queue<int> q;
        q.push(x);
        
        //marking x as visited and its level will be 0.
        vis[x]=1;
        level[x]=0;
    
        while(!q.empty())
        {
            //storing first element of queue and popping it.
            int curr = q.front();
            q.pop();
    
            //traversing adjacent vertices of current vertex.
            for(int i: adj[curr])
            {
                //if vertex is not visited, we push it in the queue, mark 
                //it as visited and store its level.
                if(!vis[i])
                {
                    q.push(i);
                    level[i] = level[curr]+1;
                    vis[i]=1;
                }
            }
        }
        //returning level of node X.
        return level[X];
    }
	
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    //arrays to store level of each node and to mark nodes as visited.
	    int vis[V]={0}, level[V]={0};
	    return bfs(adj,V,vis,level,X);
	}

};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}

  // } Driver Code Ends