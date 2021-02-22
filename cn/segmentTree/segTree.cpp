#include<bits/stdc++.h>
using namespace std;

void buildTree(int * arr,int* segT,int tN,int start,int end){

    //basecase:
    if(start==end)
    {
        segT[tN]=arr[start];
        return;
    }
    int mid = (start + end)/2;

    buildTree(arr,segT,2*tN,start,mid);
    buildTree(arr,segT,2*tN+1,mid+1,end);

    segT[tN]=segT[2*tN]+segT[2*tN+1];

}

void update(int* arr, int* segT,int start,int end,int tN, int idx, int val)
{
    //base case
    if(start==end)
    {
        segT[tN]=val; arr[start]=val;
        return;
    }

    int mid =(start+end)/2;

    if(idx<=mid)
    update(arr,segT,start,mid,2*tN,idx,val);
    else 
    update(arr,segT,mid+1,end,2*tN+1,idx,val);
    segT[tN]=segT[2*tN]+segT[2*tN+1];
}

int query(int* segT,int start, int end, int tN, int left,int right)
{
    //node is completely out of guven range
    if(start>right || left>end)return 0;
    //node completely inside l,r
    if(start>=left && end<=right)return segT[tN];
    //partially lies a node in given interval
    int mid = (start+end)/2;
    int ans1 = query(segT,start,mid,2*tN,left,right);
    int ans2 = query(segT,mid+1,end,2*tN+1,left,right);

    return ans1+ans2;
}

int main(){
    int* segT = new int[40];
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    buildTree(arr,segT,1,0,9);
    //update(arr,segT,0,9,1,5,-10);
    for(int i=0;i<10;i++)
    {
        cout<<segT[i]<<"\n";
    }
    cout<<"############### "<<query(segT,0,9,1,5,7);
}