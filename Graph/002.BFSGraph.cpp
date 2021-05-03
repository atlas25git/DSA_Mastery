// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{   
	    vector<int> ans;
	    vector<bool> visited(V,false);
	    int s=0;
	    visited[0]=true;
	    queue<int> pv;
	    
	    pv.push(0);
	    
	    while(!pv.empty())
	    {  
	       int cv = pv.front();
	       ans.push_back(cv);
	       //cout<<cv<<"---->>"<<"\n";
	       pv.pop();
	       
	       for(auto i: adj[cv])
	       {
	           if(!visited[i])
	           {
	               visited[i]=true;
	               pv.push(i);
	               
	           }
	       }
	       
	    }
    return ans;	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends