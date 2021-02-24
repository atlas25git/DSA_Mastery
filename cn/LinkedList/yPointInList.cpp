// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int n1=0, n2=0;
    Node* temp;
    
    for(temp = head1; temp; temp=temp->next)
        n1++;
        // finding length of list 1
    
    for(temp = head2; temp; temp=temp->next)
        n2++;
        // finding length of list 2
    
    for(  ; n1>n2 ; n1-- )
        head1 = head1->next;
        // if list1 is longer, we ignore some of its starting
        // elements till it has as many elements as list2
    
    for(  ; n2>n1 ; n2-- )
        head2 = head2->next;
        // similarly
        // if list2 is longer, we ignore some of its starting
        // elements till it has as many elements as list1
    
    while( head1 != head2 )
    {
        head1 = head1->next;
        head2 = head2->next;
        // now we simple traverse ahead till we get the
        // intersection point, if there is none, this loop
        // will break when both pointers point at NULL
    }
    
    if(head1) return head1->data;
    // if head1 is not NULL, we return its data
    return -1;       // otherwise we return -1
}

//first count length of both the lists
//now if length of one of the list is larger than the other, traverse the larger list to the point where both are equal
//simpy iterate the lists in a while loop till both have a diff head, as soon as they become equal stop the loop