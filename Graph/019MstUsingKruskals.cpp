// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	
	void make_set(vector<int> &v,int i)
	{
	    v[i]=i;
	}
	
	int find_set(int i,vector<int> &v)
	{
	    if(i==v[i])return i;
	    return v[i] = find_set(v[i],v);
	}
	void unify(int u,int v,vector<int> &p,vector<int> &r)
	{
	    int pu = find_set(u,p);
	    int pv = find_set(v,p);
	    
	    if(r[pu]<r[pv])swap(u,v);
	    
	    p[pu] = pv;
	    if(r[pu] == r[pv])r[pu]++;
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //1.Convert adj list into edge list,
        //2.Sort it acc to edge et
        //3.rctify it as it contains twice the entries
        //4.make set fn-> assigns rank and parent
        //6.find set fn-> recursively finds parent 
        //7.make union fn->makes parents of the lower rank one 
        //equal to the higher rank one
        //8.choose the edges if their ends belong to diff edges
        //add their cost and unify them.
        
        vector<vector<int>>res;
        
        for(int i=0;i<V;i++)
        {
            vector<int>temp;
            for(int j=0;j<adj[i].size();j++)
            {
                vector<int> r = adj[i][j];
                temp.push_back(r[1]);
                temp.push_back(min(i,r[0]));
                temp.push_back(max(i,r[0]));
                res.push_back(temp);
                temp.clear();
            }
        }
        sort(res.begin(),res.end());
        
        vector<vector<int>> graph;
        for(int i=0;i<res.size();i+=2)
        {
            graph.push_back(res[i]);
        }
        
        //cout<<"res "<<res.size()<<" Graph "<<graph.size()<<"\n";
        
        int cost = 0;
        vector<int> parent(V,-1);
        vector<int> rank(V,0);
        
        for(int i=0;i<V;i++)
        {
            make_set(parent,i);
        }
        
        for(auto e : graph){
            
            if(find_set(e[1],parent) != find_set(e[2],parent))
            {
                cost+=e[0];
                unify(e[1],e[2],parent,rank);
            }
        }
        
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends