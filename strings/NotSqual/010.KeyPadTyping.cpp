// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

string printNumber(string , int);

// User function pasted here
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,temp;
		cin>>s;
		int i,len=s.length();
		
		cout << printNumber(s,len) << "\n";
	}
	return 0;
}// } Driver Code Ends


//User function template for C++


//Function to find matching decimal representation of a string as on the keypad.
string printNumber(string s, int n)
{
    string temp="";
    
    //iterating over the string.
    for(int i=0;i<n;i++) 
    {
        //concatenating the number on the keypad which has the 
        //current character to the answer.
        
		if(s[i]=='a' || s[i]=='b' || s[i]=='c') 
		    temp.insert(i,"2");
		else if(s[i]=='d' || s[i]=='e' || s[i]=='f')
		    temp.insert(i,"3");
		else if(s[i]=='i' || s[i]=='g' || s[i]=='h')
		    temp.insert(i,"4");
		else if(s[i]=='j' || s[i]=='k' || s[i]=='l') 
		    temp.insert(i,"5");
		else if(s[i]=='m' || s[i]=='n' || s[i]=='o')
		    temp.insert(i,"6");
		else if(s[i]=='p' || s[i]=='q' || s[i]=='r' || s[i]=='s')
		    temp.insert(i,"7");
		else if(s[i]=='t' || s[i]=='u' || s[i]=='v') 
		    temp.insert(i,"8");
		else temp.insert(i,"9");
	}
	//returning the answer.
	return temp;
}