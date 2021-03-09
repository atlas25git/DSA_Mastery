// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// your task is to complete this functionh
// function should return the width of the tree
int verticalWidth(Node* root);




 // } Driver Code Ends
//User function Template for C++

/*Structure of node of binary tree is as follows
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
void lengthUtil(Node* root, int &maximum, int &minimum, int curr)
{   
    //right right right and left left left
    // base case
	if (root == NULL)return;
	
	// traverse for left
	lengthUtil(root->left, maximum, minimum, curr - 1);
	
	// update maximum and minimum
	if (minimum > curr)minimum = curr;
	if (maximum < curr)maximum = curr;
	
	// traverse for right
	lengthUtil(root->right, maximum, minimum, curr + 1);
}

int verticalWidth(Node* root)
{
    if (!root) {
        return 0;
    }
	int maximum = 0, minimum = 0;
	lengthUtil(root, maximum, minimum, 0);
	return (abs(minimum) + maximum) + 1;
}

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        
        cout << verticalWidth(root) << "\n";
    }


    return 0;
}
  // } Driver Code Ends