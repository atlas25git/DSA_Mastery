// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// design the class in the most optimal way

struct Node {
    int key;
    int value;
    Node* next,*pre;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        next=pre=NULL;
    }
};

class LRUCache
{
private:
    static unordered_map<int,Node*> hsmap;
    static int capacity,count;
    static Node* head,*tail;
public:
    // constructor for cache
    LRUCache(int cap)
    {
        unordered_map<int,Node*> temp;
        hsmap=temp;
        capacity = cap;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        head->pre = NULL;
        tail->next = NULL;
        tail->pre = head;
        count = 0;
    }
    
    static void addToHead (Node* node)
    {
       node->next = head->next;
       node->next->pre = node;
       node->pre = head;
       head->next = node;
        
    }
    
    static void deleteNode(Node* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        // node->next->pre = node->pre;
        // node->pre->next = node->next;
        //delete node;
    }
    
    // this function should return value corresponding to key
    // static int get(int key)
    // {
    //     if(hsmap.count(key)>0)
    //     {
    //         Node* node= hsmap[key];
    //         int result = node->value;
    //         deleteNode(node);
    //         addToHead(node);
    //         return result;
    //     }
    //     return -1;
    // }
    
     static int get(int key)
    {
        if (hsmap.count(key) > 0)
        {
            Node *node = hsmap[key];
            int result = node->value;
            deleteNode(node);
            addToHead(node);
            return result;
        }
        return -1;
    }
    
    // storing key, value pair
    // static void set(int key, int value)
    // {
    //   if(hsmap.count(key)>0)
    //   {
    //       Node* node = hsmap[key];
    //       node->value=value;
    //       deleteNode(node);
    //       addToHead(node);
    //   }
    //   else{
    //       Node* node = new Node(key,value);
    //       hsmap[key] = node;
    //       if(count<capacity){
    //           count++;
    //           addToHead(node);
    //       }
    //       else{
    //           hsmap.erase(tail->pre->key);
    //           deleteNode(tail->pre);
    //           addToHead(node);
    //       }
    //   }
    // }
    static void set(int key, int value)
    {
        if (hsmap.count(key) > 0)
        {
            Node *node = hsmap[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else
        {
            Node *node = new Node(key, value);
            hsmap[key] = node;
            if (count < capacity) {
                count++;
                addToHead(node);
            } else {
                hsmap.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};

unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0, 0);
Node *LRUCache::tail = new Node(0, 0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends