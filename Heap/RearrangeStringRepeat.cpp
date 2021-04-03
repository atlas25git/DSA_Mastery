// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    const int MAX_CHAR=26;
    public:
    
    struct Key
    {
    	int freq; // store frequency of character
    	char ch;
    	bool operator<(const Key &k) const
    	{
    		return freq < k.freq;
    	}
    };
    
    string rearrangeString(string str)
    {
    	int n = str.length();
    	int count[MAX_CHAR]={0};//cout<<"MArker"<<"\n";
    	//for(int i=0;i<MAX_CHAR;i++)cout<<count[i]<<" "<<i<<" ";
    	for (int i = 0 ; i < n ; i++) // storing count of character in array
    		count[str[i]-'a']++;
    		
    	priority_queue< Key > pq;
    	
    	for (char c = 'a' ; c <= 'z' ; c++)
    		if (count[c-'a'])
    			pq.push( Key { count[c-'a'], c} ); 
    	// storing pair of no. of characters and character
    	str = "" ;
    	Key prev {-1, '#'};
    	
    	while (!pq.empty())
    	{
    		Key k = pq.top();
    		pq.pop();
    		str = str + k.ch; // store the most remaining character in string
    		if (prev.freq > 0)
    			pq.push(prev); // pushing the elements with remaining freq.
    		(k.freq)--;
    		prev = k;
    	}
    	if (n != str.length())
    		return "-1";
    	else
    		return str;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	cin.ignore(INT_MAX, '\n');
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    str = ob.rearrangeString(str);
	    int flag = 1;
	    if(str != "-1"){
    	for(int i=1;i<str.length();i++){
    		if(str[i-1]==str[i])
    			flag=0;
	    }
    	if(flag == 1)
    		cout<<"1\n";
    	else
    	    cout<<"0\n";
	    }
	    else
	        cout<<"0\n";
	}
return 0;
}  // } Driver Code Ends