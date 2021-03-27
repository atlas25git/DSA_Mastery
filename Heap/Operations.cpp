// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Structure for Min Heap
struct MinHeap {
    int *harr;
    int capacity;
    int heap_size;

    // Constructor for Min Heap
    MinHeap(int c) {
        heap_size = 0;
        capacity = c;
        harr = new int[c];
    }

    ~MinHeap() { delete[] harr; }

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int); // Implemented in user editor
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

// Position this line where user code will be pasted.

// Driver code
int main() {
    int t;
    cin >> t;

    while (t--) {
        ll a;
        cin >> a;
        MinHeap h(a);
        for (ll i = 0; i < a; i++) {
            int c;
            int n;
            cin >> c;
            if (c == 1) {
                cin >> n;

                h.insertKey(n);
            }
            if (c == 2) {
                cin >> n;
                h.deleteKey(n);
            }
            if (c == 3) {
                cout << h.extractMin() << " ";
            }
        }
        cout << endl;
        // delete h.harr;
        h.harr = NULL;
    }
    return 0;
}
// } Driver Code Ends


/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/

// You need to write code for below three functions

/* Removes min element from min heap and returns it */
void MinHeap::insertKey(int k) {
    /* if (heap_size == capacity)
     {
         cout << "\nOverflow: Could not insertKey\n";
         return;
     }
  */

    harr[heap_size] = k;
    int i = heap_size;
    heap_size++;
    

    // iterating upto first index till parent is larger than the the child
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// Function to change value and store min value at first index
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// to extract minimum value in heap and then storing next mi value at first
// index
int MinHeap::extractMin() {
    if (heap_size <= 0) return -1;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1]; // putting last element at first index
    harr[heap_size - 1] = 0;
    heap_size--;

    MinHeapify(0); // calling Minheapify

    return root;
}

void MinHeap::deleteKey(int i) {
    if (i < heap_size) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}

// Function to heapify as to store minimum value at first index
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size &&
        harr[l] <
            harr[smallest]) // if value at smallest is larger change smallest
        smallest = l;
    if (r < heap_size &&
        harr[r] <
            harr[smallest]) // if value at smallest is larger change smallest
        smallest = r;
    if (smallest != i) // if smallest is not same as initial value, only then
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest); // recusrsively call Minheapify for smallest variable
    }
}