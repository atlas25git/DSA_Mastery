// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int visited[MAX][MAX];
vector<string> result;

void path(int m[MAX][MAX], int x, int y, string dir, int n) {
    if (x == n - 1 and y == n - 1) {
        result.push_back(dir);
        return;
    }

    if (m[x][y] == 0 or visited[x][y] == 1) return;

    // DFS
    visited[x][y] = 1;
    if (x > 0) path(m, x - 1, y, dir + 'U', n);
    if (y > 0) path(m, x, y - 1, dir + 'L', n);
    if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
    if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
    visited[x][y] = 0;//if it comes to this return it means no feasible solution was found in the calls preceeding.
}

vector<string> printPath(int m[MAX][MAX], int n) {
    memset(visited, 0, sizeof visited);
    result.clear();

    //The case where intial or final are unreachable.
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0) return result;

    //calling the fn.
    path(m, 0, 0, "", n);

    sort(result.begin(), result.end());
    return result;
}
