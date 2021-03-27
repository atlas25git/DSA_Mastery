//https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/
//https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isBST(Node* n, int lower, int upper)
{
    if(!n) return true;
    if( n->data <= lower || n->data >= upper ) return false;
    return (  isBST( n->left, lower, n->data )  &&  isBST( n->right, n->data, upper )  );
}

bool compare( Node* a, Node* b, vector<pair<int,int>> &mismatch )
{
    if( !a && !b ) return true;
    if( !a || !b ) return false;
    
    if( a->data != b->data )
        mismatch.push_back( pair<int,int> (a->data,b->data) );
    
    return ( compare( a->left, b->left, mismatch ) && compare( a->right, b->right, mismatch ) );
}

struct Node *correctBST( struct Node* root );

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        
        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);
        
        root = correctBST(root);
        
        // check 1: is tree now a BST
        if( ! isBST(root, INT_MIN, INT_MAX) )
        {
            cout<< "0\n";
            continue;
        }
        
        // check 2: comparing with duplicate tree
        
        vector<pair<int,int>> mismatch;
        // a vector to store data of mismatching nodes
        
        if( ! compare( root, duplicate, mismatch) )
        {
            // false output from this function indicates change in structure of tree
            cout<< "0\n";
            continue;
        }
        
        // finally, analysing the mismatching nodes
        if( mismatch.size() !=2 || mismatch[0].first!=mismatch[1].second || mismatch[0].second!=mismatch[1].first )
            cout<<"0\n";
        else cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*Complete the function
Node is as follows:

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

*/

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

// This function does inorder traversal to find out the two swapped nodes. 
// It sets three pointers, first, middle and last.  If the swapped nodes are 
// adjacent to each other, then first and middle contain the resultant nodes 
// Else, first and last contain the resultant nodes 
void correctBSTUtil( struct Node* root, struct Node** first,
                     struct Node** middle, struct Node** last,
                     struct Node** prev )
{
    if( root )
    {
        // Recur for the left subtree
        correctBSTUtil( root->left, first, middle, last, prev );
        
        // If this node is smaller than the previous node, it's violating 
        // the BST rule.
        //coz inorder traversal
        if (*prev && root->data < (*prev)->data)
        {
            
            // If this is first violation, mark these two nodes as 
            // 'first' and 'middle'
            if ( !*first )
            {
                *first = *prev;
                *middle = root;
            }
            
            // If this is second violation, mark this node as last
            else
                *last = root;
        }
        
        // Mark this node as previous 
        *prev = root;
        
        // Recur for the right subtree 
        correctBSTUtil( root->right, first, middle, last, prev );
    }
}

// A function to fix a given BST where two nodes are swapped.  This 
// function uses correctBSTUtil() to find out two nodes and swaps the 
// nodes to fix the BST 
struct Node *correctBST( struct Node* root )
{
    // Initialize pointers needed for correctBSTUtil() 
    struct Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    
    // Set the poiters to find out two nodes 
    correctBSTUtil( root, &first, &middle, &last, &prev );
    
    // Fix (or correct) the tree 
    //The point of contention here is that, there might be 2 cases
    //if the two violated cases are just in one place next to each other
    //and when they are seperated.
    //for this we create an extra pointer, and swap nodes based upon the value
    //in this last node.
    if( first && last )
        swap( &(first->data), &(last->data) );
    else if( first && middle ) // Adjacent nodes swapped
        swap( &(first->data), &(middle->data) );
        
        
    // else nodes have not been swapped, passed tree is really BST. 
	return root;
}