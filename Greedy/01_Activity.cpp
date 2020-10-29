#include<bits/stdc++.h>

using namespace std;

bool paircompare(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
//used to find the activity order.
int find(int a,vector<pair<int,int>> b)
{
    int i;
    for(i=0;i<b.size();i++)
    {
        if(a==b[i].second)
        {
            return i+1;
        }
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i;
	    int s[n],f[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>f[i];
	    }
	    
	    vector<pair<int,int>> x;
	     
	    for(i=0;i<n;i++)
	    {
	        x.push_back(make_pair(s[i],f[i]));
	       
	    }
	   
	    vector<pair<int,int>> y=x;
	    //Sorting according to the finish time
	    sort(x.begin(), x.end(), paircompare);
	    
	    int last=0;
	    
	   for(i=0;i<n;i++)
	   {    //printing the activity in order of which they'd be held. 
	        //The one ending earliest will always be the first. 
	       if(x[i].first>last)
	       {    //find function here is used to find the particular index of such activity order
	           cout<<find(x[i].second,y)<<" ";
	           last=x[i].second;
	       }
	   }
	   cout<<endl;
	}
	return 0;
}