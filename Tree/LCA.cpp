// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node * lca(Node* root,int n1,int n2);
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        cout<<lca(root,a,b)->data<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return 
   NULL. Else if left subtree contains any 
   of them return pointer to left.*/

// bool findP(Node* root, int n,vector<Node*> &v )
// {
//     if(root == NULL)return false;
    
//     v.push_back(root);
//     if(root->data == n)return true;
    
//     if(findP(root->left,n,v) || findP(root->right,n,v))return true;
    
//     v.pop_back();
//     return false;
    
// }


// Node* lca(Node* root ,int n1 ,int n2 )
// {
//   //Your code here 
//   vector<Node*> p1,p2;
//   if(findP(root,n1,p1)==false || findP(root,n2,p2)==false)return NULL;
   
//   for(int i=0;i<p1.size()-1 && i<p2.size()-1;i++)
//   {
//       if(p1[i+1]!=p2[i+1])return p1[i];
       
//   }
//   return NULL;
   
// }

Node * lca(Node* root,int n1,int n2)
{
    
    // base case
  if(root==NULL)
    return NULL;

  // If either n1 or n2 matches with root's key, report 
  // the presence by returning root (Note that if a key is 
  // ancestor of other, then the ancestor key becomes LCA 
  if(root->data==n1 or root->data==n2)
    return root;
    
  // Look for keys in left and right subtrees
  Node *l = lca(root->left,n1,n2);
  Node *r = lca(root->right,n1,n2);
  
  // If both of the above calls return Non-NULL, then one key
  // is present in once subtree and other is present in other, 
  // So this node is the LCA 
  if (l and r)
    return root;

  // Otherwise check if left subtree or right subtree is LCA
  return (l!=NULL)?l:r;
}

// bool findPath(Node *root, vector<Node *> &p, int n){
//     if(root==NULL)return false;
//     p.push_back(root);
//     if(root->data==n)return true;
    
//     if(findPath(root->left,p,n)||findPath(root->right,p,n))return true;
    
//     p.pop_back();
//     return false;
// }

// Node *lca(Node *root, int n1, int n2){
//     if(root==NULL)return NULL;
//     vector <Node *> path1, path2;
//     if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
//         return NULL;
//     for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
//         if(path1[i+1]!=path2[i+1])
//             return path1[i];
//     return NULL;
// }