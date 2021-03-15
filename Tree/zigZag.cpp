// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
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

// return a vector containing the zig zag level order traversal of the given tree
// vector <int> zigZagTraversal(Node* root)
// {
//     vector <int> res; 
// 	if (!root)return res;
// 	stack<struct Node*> currentlevel;
// 	stack<struct Node*> nextlevel;
// 	currentlevel.push(root);
// 	bool lefttoright = true;
// 	while (!currentlevel.empty())
// 	{
// 		Node* temp = currentlevel.top();
// 		currentlevel.pop();
// 		if (temp) {
// 			res.push_back (temp->data);
// 			if (lefttoright) {
// 				if (temp->left)
// 					nextlevel.push(temp->left);
// 				if (temp->right)
// 					nextlevel.push(temp->right);
// 			}
// 			else {
// 				if (temp->right)
// 					nextlevel.push(temp->right);
// 				if (temp->left)
// 					nextlevel.push(temp->left);
// 			}
// 		}
// 		if (currentlevel.empty()) {
// 			lefttoright = !lefttoright;
// 			swap(currentlevel, nextlevel);
// 		}
// 	}
// 	return res;
// }

// // create 2 stacks current_level and the next_level
// start from current level and fill in the next level's nodes in stack
// depicted by next_level;
// ust ensure the order by maintaining the order to be followed in the 
// specific level.
// when a level is exhausted i.e, all the nodes popped
// switch to the other stack using swap function.


vector <int> zigZagTraversal(Node* root)
{
    vector<int> v;
    stack<Node*> cl,nl;
    cl.push(root);
    bool lToR = true;
    while(!cl.empty())
    {
        
        Node* curr = cl.top();
        cl.pop();
        
        v.push_back(curr->data);
            if(lToR)
            {
                if(curr->left)nl.push(curr->left);
                if(curr->right)nl.push(curr->right);
            }
            else {
                if(curr->right)nl.push(curr->right);
                if(curr->left)nl.push(curr->left);
                 }
            
        
        
        if(cl.empty())
        {
            lToR = !lToR;
            swap(cl,nl);
        }
        
    }
    
    return v;
}