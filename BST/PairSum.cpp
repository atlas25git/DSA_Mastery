// { Driver Code Starts
// Initial Template for C++

// CPP program to find a pair with
// given sum using hashing
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends


/* BST Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

// This function should return true
// if there is a pair in given BST with
// given sum.
// Back-end complete function Template for C++

bool fpp(Node* root,int sum,unordered_set<int>&s)
{
    if(root == NULL)return false;
    if(s.find(sum-root->data) != s.end())return true;
    else s.insert(root->data);
    
    if (fpp(root->left,sum,s))return true;
    else return fpp(root->right,sum,s);
}


bool findPair(Node* root, int sum) {
    unordered_set<int> s;
    if(fpp(root,sum,s))return true;
    else return false;
}

// bool findpairUtil(Node* root, int sum, unordered_set<int>& set) {
    
//     // base case
//     if (root == NULL) return false;

//     // recurse for left subtree
//     if (findpairUtil(root->left, sum, set)) return true;

//     // check if pair with given sum exists
//     if (set.find(sum - root->data) != set.end()) {
//         return true;
//     } 
//     else
//         set.insert(root->data);

    
//     // recurse for right
//     return findpairUtil(root->right, sum, set);
// }

// bool findPair(Node* root, int sum) {
//     unordered_set<int> set;
    
//     if (findpairUtil(root, sum, set)) return true;

//     return false;
// }
