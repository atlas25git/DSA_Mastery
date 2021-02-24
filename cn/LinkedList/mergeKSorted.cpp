// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

Node* sortM(Node* a, Node* b)
{   
    Node* temp = NULL;
    if(a==NULL)return b;
    else if(b==NULL)return a;
    
    if(a->data <= b->data)
    {
        temp = a;
        temp->next = sortM(a->next,b);
        
    }
    
    else
    {
        temp = b;
        temp->next = sortM(a,b->next);
        
    }
    return temp;
}
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       int last = N-1;
        while(last!=0)//will end up when whole array has been traversed, i.e., j from n comes down to 0 
        {
            int i = 0, j =last;
            while(i<j)
            {
                arr[i] = sortM(arr[i],arr[j]);
                i++,j--;
                
                if(i>=j)last = j;
                
            }
        }
        return arr[0];
}

