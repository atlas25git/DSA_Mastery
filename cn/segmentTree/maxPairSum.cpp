#include<bits/stdc++.h>
using namespace std;

struct node
{
    int max; int smax;
}

void buildTree(int* arr, node* tree, int tN, int start,int end)
{
    //base case:
    if(start==end)
    {
        tree[tN].max=arr[start];
        tree[tN].smax=INT_MIN;
        return;
    }

    int mid = (start+end)/2;
    buildTree(arr,tree,2*tN,start,mid);
    buildTree(arr,tree,2*tN+1,mid+1,end);
    
    node left=tree[2*tN];
    node right=tree[2*tN+1];

    tree[tN].max=max(left.max,right.smax);
    tree[tN].smax=min(max(left.max))


}

int main(){
    int arr[]={10,9,8,6,11,12,13,14,15};

}