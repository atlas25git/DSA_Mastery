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
/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
  public:
    void inorder(Node *root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    
    
    
    
    Node *minValueNode(Node *nod)
    {
        Node *current = nod;
        while(current->left !=NULL)
            current = current->left;
        return current;
    }
    
    
    vector<int> merge(Node *root1,Node *root2)
    {
        stack<Node *> s1;
        stack<Node *> s2;
        Node *c1 = root1;
        Node *c2 = root2;
    
        vector<int> ans;
        
        // inorder on root2 if root1 is null
        if(root1==NULL)
        {
            inorder(root2, ans);
            return ans;
        }
        
        // inorder on root1 if root2 is null
        if(root2==NULL)
        {
            inorder(root1, ans);
            return ans;
        }
        
        // Run the loop while there are nodes not yet printed.  
        // The nodes may be in stack(explored, but not printed)  
        // or may be not yet explored  
        while(c1!=NULL or !s1.empty() or c2!=NULL or !s2.empty())
        {
            // Following steps follow iterative Inorder Traversal  
            if(c1!=NULL or c2!=NULL)
            {
                // Reach the leftmost node of both BSTs and push ancestors of  
                // leftmost nodes to stack s1 and s2 respectively 
                if(c1!=NULL)
                {
                    s1.push(c1);
                    c1 = c1->left;
                }
                
                if(c2!=NULL)
                {
                    s2.push(c2);
                    c2 = c2->left;
                }
            }
            
            else 
            {
                // If we reach a NULL node and either of the stacks is empty,  
                // then one tree is exhausted, ptint the other tree  
                if(s1.empty())
                {
                    while(!s2.empty())
                    {
                        c2  = s2.top();
                        s2.pop();
                        c2->left= NULL;
                        inorder(c2, ans);
                    }
                    return ans;
                }
                
                if(s2.empty())
                {
                    while(!s1.empty())
                    {
                        c1  = s1.top();
                        s1.pop();
                        c1->left = NULL;
                        inorder(c1, ans);
                    }
                    return ans;
                }
                
                // Pop an element from both stacks and compare the  
                // popped elements  
                c1 = s1.top();
                c2  = s2.top();
                s1.pop();
                s2.pop();
                
                // If element of first tree is smaller, then print it
                // and push the right subtree. If the element is larger,
                // then we push it back to the corresponding stack.
                if(c1->data < c2->data)
                {
                    ans.push_back(c1->data);
                    c1 = c1->right;
                    s2.push(c2);
                    c2 = NULL;
                }else
                {
                    ans.push_back(c2->data);
                    c2 = c2->right;
                    s1.push(c1);
                    c1 = NULL;
                }
            }
        }
        return ans;
    }

};

// { Driver Code Starts.
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
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends