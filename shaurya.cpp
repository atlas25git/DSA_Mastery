#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};

void TraverseLL(node *head)
{
	node *current = head;
    if(current == NULL)cout<<"fkd Insertion"<<endl;
	while(current!=NULL)
	{
		cout<<current->data<<" ";
		current=current->next;
	}
}

void InsertEnd(node*& head, int x)
{	
	node*temp= new node(x);
	if(head==NULL) head=temp;
	else{
	node* current = head;
	while(current->next!=NULL)
		current=current->next;
		
	current->next=temp;
    }
	//return head;
}

void CreateLL(node*& head,int n)//coberted node - node*
{	
    //node* curr1 = head;
	int d;
	for(int i=1;i<=n;i++)
	{
		cout<<"\nInsert element "<<i<<" : ";
		cin>>d;
		InsertEnd(head,d);
	}
	//head = curr1;
	cout<<"\nLinked List : ";
	TraverseLL(head);

    //return head;
	
}

void Insert(node*& head, int pos, int data)
{	
	node *temp = new node(data);
	if(pos==0)//changed 1 to 0 
	{	
        temp->next=head;
        head = temp;
		//return temp;
	}
	
	node *curr=head;

    if(curr==NULL) return;
    else{
	for(int i=0; i <= pos-1; i++)
		{curr=curr->next;}
		
	
	
	temp->next=curr->next;
	curr->next=temp;
    }
	//return head;
}
	
int main()
{	
    freopen("input.txt","r",stdin);
    int n,pos,data;
	cout<<"Number of nodes : ";
	cin>>n;
	node *head = NULL;
    node*& h1 = head;
	CreateLL(head,n); //stored in head
    //TraverseLL(head);	
	if(head==NULL)cout<<"HEAD:->NULL";
	cout<<"\n\nEnter position of new node : ";
	cin>>pos;
	cout<<"\n\nEnter data of new node : ";
	cin>>data; 
	
	Insert(head,pos,data);
	
	cout<<"\n\nNew LL : ";
	TraverseLL(head);	
}