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

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
    itr=itr->left;
    do{
        cout<<itr->data<<" ";
        itr=itr->left;
    }while(head!=itr);
    cout<<itr->data<<endl;
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


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Node *head = bTreeToCList(root);
        displayCList(head);
    }
    return 0;
}







// } Driver Code Ends


/*Complete the function below
Node is as follows:
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
// 1. The idea can be described using below steps.
// 1) Write a general purpose function that concatenates two given circular doubly lists (This function is explained below).
// 2) Now traverse the given tree
// ….a) Recursively convert left subtree to a circular DLL. Let the converted list be leftList.
// ….a) Recursively convert right subtree to a circular DLL. Let the converted list be rightList.
// ….c) Make a circular linked list of root of the tree, make left and right of root to point to itself.
// ….d) Concatenate leftList with list of single root node.
// ….e) Concatenate the list produced in step above (d) with rightList.

// 2. How to Concatenate two circular DLLs?

// Get the last node of the left list. Retrieving the last node is an O(1) operation, since the prev pointer of the head points to the last node of the list.
// Connect it with the first node of the right list
// Get the last node of the second list
// Connect it with the head of the list.


// Node *concatenate(Node *leftList, Node *rightList)
// {    
//     // If either of the list is empty 
//     // then return the other list 
//     if (leftList == NULL)
//         return rightList;
//     if (rightList == NULL)
//         return leftList;
        
//     // Store the last Node of left List 
//     Node *leftLast = leftList->left;
    
//     // Store the last Node of left List 
//     Node *rightLast = rightList->left;
    
//     // Store the last Node of left List 
//     leftLast->right = rightList;
//     rightList->left = leftLast;
    
//     // Store the last Node of left List 
//     leftList->left = rightLast;
    
//     // Store the last Node of left List 
//     rightLast->right = leftList;
//     return leftList;
// }

// Node *bTreeToCList(Node *root)
// {
//     if (root == NULL)
//         return NULL;
        
//     Node *left = bTreeToCList(root->left);
//     Node *right = bTreeToCList(root->right);
    
//     // Make a circular linked list of single node 
//     // (or root). To do so, make the right and 
//     // left pointers of this node point to itself 
//     root->left = root->right = root;
    
//     // Step 1 (concatenate the left list with the list  
//     //         with single node, i.e., current node) 
//     // Step 2 (concatenate the returned list with the 
//     //         right List) 
//     return concatenate(concatenate(left, root), right);
// }

// 1) Create a fn to concatenate two cll.
// 2) make a fn to form cll from given node.
// 3) it'll return left,right and then make a single node cll of root;
// 4) Now pass these in conatenating fn.

Node* concatenate(Node* leftl, Node* rightl)
{
    if(leftl == NULL) return rightl;
    if(rightl == NULL) return leftl;
    
    Node* llast = leftl->left;
    Node* rlast = rightl->left;
    
    llast->right = rightl;
    rightl->left = llast;
    
    rlast->right = leftl;
    leftl->left = rlast;
    
    return leftl;
}

Node* bTreeToCList(Node* root)
{
    if(root == NULL) return root;
    
    Node* leftl = bTreeToCList(root->left);
    Node* rightl= bTreeToCList(root->right);
    
    root->left= root->right = root;
    
    return concatenate(concatenate(leftl, root), rightl);
    
}

 