// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


 // } Driver Code Ends
/*Node structure

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

class Solution{
public:
    vector <int> findCommon(Node *root1, Node *root2)
    {
        // Create two stacks for two inorder traversals
	    stack<Node *> stack1, s1, s2;
        vector <int> res; 
	    while (1)
	    {
	        // push the Nodes of first tree in stack s1 
		    if (root1)
		    {
			    s1.push(root1);
			    root1 = root1->left;
		    }
		
		    // push the Nodes of second tree in stack s2
		    else if (root2)
		    {
			    s2.push(root2);
			    root2 = root2->left;
		    }
		
		    // Both root1 and root2 are NULL here 
		    else if (!s1.empty() && !s2.empty())
		    {
    			root1 = s1.top();
			    root2 = s2.top();
    			
	    		// If current keys in two trees are same
		    	if (root1->data== root2->data)
			    {
				    res.push_back (root1->data);
				    s1.pop();
    				s2.pop();
	    			root1 = root1->right;
		    		root2 = root2->right;
			    }
                //Smallest Value if it is greater than the others smallest value,
                //then the latter would have greater values which might be equal
                // move to the inorder successor 
    			else if (root1->data< root2->data)
	    		{
		    	    // If Node of first tree is smaller, than that of 
                    // second tree, then its obvious that the inorder 
                    // successors of current Node can have same value 
                    // as that of the second tree Node. Thus, we pop 
                    // from s1
		    		s1.pop();
			    	root1 = root1->right;
				    
    				// root2 is set to NULL, because we need 
                    // new Nodes of tree 1 
		    		root2 = NULL;
			    }
			    else if (root1->data> root2->data)
    			{
	    			s2.pop();
		    		root2 = root2->right;
			    	root1 = NULL;
    			}
	    	}
		
    		// Both roots and both stacks are empty 
	    	else break;
	    }   
	    return res;
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
} 