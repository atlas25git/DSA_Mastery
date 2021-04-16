// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

int majorityWins(int arr[], int n, int x, int y) {
    int count_x = 0;
    int count_y = 0;

    // Iterating through the array elements.
    // Incrementing the counter variables accordingly.
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count_x++;
        if (arr[i] == y) count_y++;
    }
    
    // Comparing the two counters.
    if (count_x > count_y)
        // Returning the number with more appearances in the array.
        return x;
    else if (count_y > count_x)
        // Returning the number with more appearances in the array.
        return y;
    
        // If both appear same number of times, returning the smaller number.
    else
        return x < y ? x : y;
}

// { Driver Code Starts.
int main() {

    int t; // Testcases
    cin >> t; // Input the testcases
    while (t--) // Until all testcases are exhausted
    {
        int n; // Size of array
        cin >> n; // Input the size
        int arr[n]; // Declaring array of size n
        for (int i = 0; i < n;
             i++) // Running a loop to input all elements of arr
            cin >> arr[i];

        int x, y; // declare x and y
        cin >> x >> y; // input x and y
        Solution obj;
        cout << obj.majorityWins(arr, n, x, y)
             << endl; // calling the function that you complete
    }

    return 0;
}  // } Driver Code Ends