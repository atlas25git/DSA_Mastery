// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 

class Solution{
    public:
    void printWordsUtil(int number[], int curr_digit, string output, int n, vector <string> &res) 
    {
        // Base case, if current output word is prepared 
        int i; 
        if (curr_digit == n) 
        { 
            res.push_back(output);
            return ; 
        } 
      
        // Try all 3 possible characters for current digir in number[] 
        // and recur for remaining digits 
        for (i=0; i<strlen(hashTable[number[curr_digit]]); i++) 
        { 
            output.push_back(hashTable[number[curr_digit]][i]); 
            printWordsUtil(number, curr_digit+1, output, n, res); 
            // if (number[curr_digit] == 0 || number[curr_digit] == 1) 
            //     return; 
            output.pop_back();
        } 
    } 
    
    vector<string> possibleWords(int a[], int N)
    {
        vector <string> res;
        string result;
        printWordsUtil(a, 0, result, N, res); 
        return res;
        
    }
};

// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends