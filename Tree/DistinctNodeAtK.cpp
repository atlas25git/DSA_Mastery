// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


int printKDistantfromLeaf(Node* node, int k);

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
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/

//This function returns the count of the total distinct nodes that are at a 
//distance k from leaf nodes.

void kDistantFromLeafUtil(Node* node, int &counter, bool visited[],int pathLen, int k)
{
	// Base case
	if (node==NULL) return;

	/* append this Node to the path array */
	visited[pathLen] = false;
	pathLen++;

	/* it's a leaf, so print the ancestor at distance k only
	if the ancestor is not already printed */
	if (node->left == NULL && node->right == NULL && //ef case, calculating dis. from top
		pathLen-k-1 >= 0 && visited[pathLen-k-1] == false)
	{
		//cout << path[pathLen-k-1] << " ";
		counter++;
		visited[pathLen-k-1] = true;
		return;
	}

	/* If not leaf node, recur for left and right subtrees */
	kDistantFromLeafUtil(node->left, counter, visited, pathLen, k);
	kDistantFromLeafUtil(node->right, counter, visited, pathLen, k);
	
}
int printKDistantfromLeaf(Node* node, int k)
{
	int counter = 0;
	bool visited[MAX_HEIGHT] = {false};
	kDistantFromLeafUtil(node, counter, visited, 0, k);
	return counter;
}