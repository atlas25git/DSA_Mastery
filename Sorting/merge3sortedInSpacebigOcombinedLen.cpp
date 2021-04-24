// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 


void printVector(const vector<int>& a) 
{ 
    for (auto e : a) { 
        cout << e << " "; 
    }
    cout<<endl;
} 

 // } Driver Code Ends

class Solution{
  public:

    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        int m, n, o, i, j, k; 
        //Storing the size of the three vectors. 
        m = A.size(); 
        n = B.size(); 
        o = C.size(); 
    
        //Creating a vector for storing output.
        vector<int> D; 
        D.reserve(m + n + o); 
    
        i = j = k = 0; 
        
        //Using three pointers over the three vectors which helps in choosing
        //and storing the smallest element in the output vector.
        while (i < m && j < n && k < o) { 
    
            //Finding minimum of A[i], B[j] and C[k].
            int minn = min(min(A[i], B[j]), C[k]); 
    
            //We store the minimum value in output vector. 
            D.push_back(minn); 
    
            //Incrementing the pointer which had the minimum value.
            if (minn == A[i]) 
                i++; 
            else if (minn == B[j]) 
                j++; 
            else
                k++; 
        } 
    
        //If C has exhausted(its pointer has crossed last element) then 
        //we continue storing the minimum values from other two vectors.
        while (i < m && j < n) { 
            if (A[i] <= B[j]) { 
                D.push_back(A[i]); 
                i++; 
            } 
            else { 
                D.push_back(B[j]); 
                j++; 
            } 
        } 
    
        //If B has exhausted(its pointer has crossed last element) then
        //we continue storing the minimum values from other two vectors. 
        while (i < m && k < o) { 
            if (A[i] <= C[k]) { 
                D.push_back(A[i]); 
                i++; 
            } 
            else { 
                D.push_back(C[k]); 
                k++; 
            } 
        } 
    
        //If A has exhausted(its pointer has crossed last element) then 
        //we continue storing the minimum values from other two vectors.
        while (j < n && k < o) { 
            if (B[j] <= C[k]) { 
                D.push_back(B[j]); 
                j++; 
            } 
            else { 
                D.push_back(C[k]); 
                k++; 
            } 
        } 
    
        //If A and B have exhausted(their pointer has crossed last element) then
        //we continue storing the minimum values from the last vector C.
        while (k < o) 
            D.push_back(C[k++]); 
    
        //If B and C have exhausted(their pointer has crossed last element) then
        //we continue storing the minimum values from the last vector A.
        while (i < m) 
            D.push_back(A[i++]); 
    
        //If A and C have exhausted(their pointer has crossed last element) then
        //we continue storing the minimum values from the last vector B.
        while (j < n) 
            D.push_back(B[j++]); 
        
        //returning the resultant vector.
        return D; 
    } 

};

// { Driver Code Starts.

int main() 
{ 


    int t;
    cin>>t;
    while(t--){
    int n,m,o;
    cin>>n>>m>>o;
    vector<int> A,B,C;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        A.push_back(x);
    }
    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        B.push_back(x);
    }
    
    for(int i=0;i<o;i++){
        int x;
        cin>>x;
        C.push_back(x);
    }

    Solution obj;
    vector<int>ans = obj.mergeThree(A, B, C);
    for(auto i: ans)cout << i << " ";
    cout << "\n";
    // obj.printVector(mergeThree(A, B, C)); 
    
    }
   
    return 0; 
} 
  // } Driver Code Ends