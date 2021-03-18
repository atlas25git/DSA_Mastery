
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



struct Node* deleteNode(struct Node* root, int key);

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root1 = buildTree(s);
    getline(cin, s);
    int k = stoi(s);
    root1  = deleteNode(root1, k);
    vector<int> v;
    inorder(root1, v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified BST after deleting the node with value X
// Node *minValueNode(Node *nod)
// {
//     Node *current = nod;
//     while(current->left !=NULL)
//         current = current->left;
//     return current;
// }

// Node* deleteNode(Node* root, int key){    
//     // base case
//     if (root == NULL) return root;
    
//     // check if key is less than the data of root
//     if (key < root->data)
//         root->left = deleteNode(root->left, key);
    
//     // else check if key is greater than data of root
//     else if (key > root->data)
//         root->right = deleteNode(root->right, key);
    
//     // if key is same as root's key, then This is the node 
//     // to be deleted 
//     else
//     {
//         // node with only one child or no child 
//         if (root->left == NULL)
//         {
//             struct Node *temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//             struct Node *temp = root->left;
//             free(root);
//             return temp;
//         }
        
//         // node with two children: Get the inorder successor (smallest 
//         // in the right subtree) 
//         struct Node* temp = minValueNode(root->right);
        
//         // Copy the inorder successor's content to this node
//         root->data = temp->data;
        
//         // Delete the inorder successor
//         //deleting the one whose value we just replaced
//         root->right = deleteNode(root->right, temp->data);
//     } 
//     return root;
// }

Node* getLow(Node* root)
{
    if(root->right == NULL) return root;
    getLow(root->right);
}

Node* deleteNode(Node* root, int key){
    
    if(root == NULL) return root;
    
    else if(key>root->data)
        root->right = deleteNode(root->right,key);
    else if( key<root->data)
        root->left = deleteNode(root->left,key);
        
        else{
            //nullity of both the nodes would be handled implicitly here
            if(root->left == NULL){
                Node* temp = new Node(root->data);
                free(root);
                return temp;
            }
            else if(root->right == NULL){
                Node* temp = new Node(root->data);
                free(root);
                return temp;
            }
            else{
                Node* temp = getLow(root->left);
                root->data = temp->data;
                root->left = deleteNode(root->left,temp->data);
            }
        }
    
}
