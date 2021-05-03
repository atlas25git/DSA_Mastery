// { Driver Code Starts
//Initial Template for C++

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

using namespace std;


 // } Driver Code Ends
//User function Template for C++


//Function to fill lps[] for given patttern pat[0..M-1].


void fillLPS(string str, int *lps){
    int n=str.length(),len=0;
    lps[0]=0;
    int i=1;
    while(i<n){
        if(str[len]==str[i])
        {
            len++;
            lps[i]=len;
            i++;
            
        }
        else
        {
            if(len==0)
                {   
                    lps[i]=0;
                    i++;
                    
                }
            else{
                len=lps[len-1];
                
            }
        }
    }
}
bool KMPSearch(string pat,string txt){
    int N=txt.length();
    int M=pat.length();
    int lps[M];
    fillLPS(pat,lps);
    int i=0,j=0;
    while(i<N){
        if(pat[j]==txt[i]){i++;j++;}

        if (j == M) { 
           return true; 
            j = lps[j - 1]; 
        } 
        else if (i < N && pat[j] != txt[i]) { 
            if (j == 0) 
                i++;
            else
                j = lps[j - 1];  
        }
    }
    return false;
}


// { Driver Code Starts.

// Driver program to test above function 
int main() 
{ 
    int t;
    std::cin >> t;
    
    while(t--){
        string s, pat;
        cin >> s >> pat;
        if(KMPSearch(pat, s)){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    
	return 0;
} 
  // } Driver Code Ends