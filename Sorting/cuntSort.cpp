// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    string countSort(string arr){
        
        
        char output[arr.length()];
    
        //Creating a count array to store count of individual
        //characters and initialize count array as 0.
        //cout<<":::::::::::"<<RANGE<<":::::::::::::::";
        int count[255 + 1], i;
        memset(count, 0, sizeof(count));
    
        //Storing count of each character.
        for(i = 0; arr[i]; ++i)
            ++count[arr[i]];
    
        //Modifying the count array such that each element at each index 
        //stores the sum of previous counts. 
        //The modified count array indicates the position of each object in 
        //the output sequence.
        
        for (i = 1; i <= RANGE; ++i)
        {
            count[i] += count[i-1];
        }
        //Building the output character array.
        //the count present at a particular element used as index,
        //corresponds to it's position in the array and subsequently even after
        //reduction if it is encountered again then too the property will hold.
        for (i = 0; arr[i]; ++i)
        {
            output[count[arr[i]]-1] = arr[i];
            --count[arr[i]];
        }
    
        //Copying the output array to arr, so that arr now
        //contains sorted characters.
        for (i = 0; arr[i]; ++i)
            arr[i] = output[i];
            
        //returning the sorted string.    
        return arr;
    }
};   



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}
  // } Driver Code Ends