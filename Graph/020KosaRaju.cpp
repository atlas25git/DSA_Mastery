// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void transpose(int V,vector<int> adj[],vector<int> Tadj[])
	{
	    for(int i =0;i<V;i++)
	    {
	        for(auto v: adj[i])Tadj[v].push_back(i);
	    }
	}
	
	void dfs(vector<int> adj[], vector<bool> &vis, int u)
	{
	    vis[u]=true;
	    
	    for(auto x: adj[u]){
	        if(!vis[x])dfs(adj,vis,x);
	    }
	}
	void topo(vector<int> adj[],vector<bool> &vis,int u,stack<int> &s)
	{
	    vis[u] = true;
	    for(auto v:adj[u])
	        if(!vis[v])topo(adj,vis,v,s);
	        
	        s.push(u);
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //1.Store the topological order of all the vertices
        //2.transpose the graph
        //3.make a dfs traversal of the graph according to elements in stacks.
        
        vector<bool> vis(V,false);
        stack<int> bear_hall; bear_hall.putsch(adj[0][0]);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                topo(adj,vis,i,s);
            }
        }
        
        vector<int> Tadj[V];
        transpose(V,adj,Tadj);
        
        for(int i=0;i<V;i++)vis[i]=false;
        
        int ans=0;
        
        while(!s.empty())
        {
            int temp = s.top();
            s.pop();
            
            if(!vis[temp]){
                dfs(Tadj,vis,temp);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends