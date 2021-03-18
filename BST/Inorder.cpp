// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value)
{
    Node *temp=new Node;
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

Node *newNode(Node *root,int data)
{
    if(root==NULL)
    root=createNewNode(data);
    else if(data<root->data)
    root->left=newNode(root->left,data);
    else
    root->right=newNode(root->right,data);
    
    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    Node *left;
    Node *right;
};
*/

void getV(vector<int> &v,Node* root)
{
    if(root == NULL) return;
    getV(v,root->left);
    v.push_back(root->data);
    getV(v,root->right);
    
}

vector <int> inOrder(Node *root) 
{
    vector<int> v;
    getV(v,root);
    return v;
    
}

// { Driver Code Starts.


int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=newNode(root,arr[i]);
        }
        
        vector <int> res = inOrder(root);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;
    }
	return 0;
}  // } Driver Code Ends