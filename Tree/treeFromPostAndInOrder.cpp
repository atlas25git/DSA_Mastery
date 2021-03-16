// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

int search(int arr[], int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
}

Node* cTree(int* in,int* post,int is,int ie,int& index,int n)
{   
    if(is>ie) return NULL;
    
    Node* tNode = new Node(post[index--]);
    //(*index)--;
    //cout<<index<<"\n";
    
    if(is == ie)return tNode;
    
    
    int isIns;
     for(int i=0;i<n;i++)
         if(in[i] == tNode->data)isIns = i;
    tNode->right = cTree(in,post,isIns+1,ie,index,n);
    tNode->left = cTree(in,post,is,isIns-1,index,n);
    
    
    return tNode;
    
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    
    int index = n-1;
    return cTree(in,post,0,n-1,index,n);
}


