// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
  
    bool isAnagram(string c, string d)
    {
    //an array of size 26, to store count of characters.
    int a[26] = {0};
    
    //storing count of each character in first string.
    for(int i = 0; i < c.length(); i++){
        a[c[i]-'a']++;
    }

    //decrementing the count of characters encountered in the second string.
    for(int i = 0; i < d.length(); i++){
        a[d[i]-'a']--;
    }

    bool flag = true;
    
    //iterating over the array in which we stored the count initially 
    //to check if count at every index is equal to 0 or not.
    //count 0 indicates that number of characters in both strings are same.
    for(int i = 0;i<26;i++)
    {
        if(a[i] != 0){
            flag = false;
            break;
        }
    }
    //returning the result.
    return flag;
    }
    
    

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends