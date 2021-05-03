// { Driver Code Starts
//Initial Template for C++

/* Following program is a C implementation of 
Rabin Karp. Algorithm given in the CLRS book */
#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends
//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

//Function to check if the pattern is present in string or not.
bool search(string pat, string txt, int q) 
{ 
	int M = pat.length(); 
	int N = txt.length(); 
	int i, j; 
	int p = 0; 
	int t = 0; 
	int h = 1; 

	//the value of h would be "pow(d, M-1)%q".
	for (i = 0; i < M-1; i++) 
		h = (h*d)%q; 

	//calculating the hash value of pattern and first window of text. 
	for (i = 0; i < M; i++) 
	{ 
		p = (d*p + pat[i])%q; 
		t = (d*t + txt[i])%q; 
	} 

	//sliding the pattern over text one by one. 
	for (i = 0; i <= N - M; i++) 
	{ 
		//checking the hash values of current window of text and pattern. 
		//If the hash values match then only we check for characters on by one.
		if ( p == t ) 
		{ 
			//checking for characters one by one.
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 
			//if pattern is found, we return true.
			if (j == M) 
				return true;
		} 

		//calculating hash value for next window of text.
		//removing leading digit and adding trailing digit.
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			//we might get negative value of t so converting it to positive. 
			if (t < 0) 
			t = (t + q); 
		} 
	}
	//returning false if pattern is not found.
	return false;
} 

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 
  // } Driver Code Ends