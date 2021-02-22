#include<bits/stdc++.h>

using namespace std;

void buildTree(int* segT, int* ar,int start,int end,int tN)
{
    if(start==end)
    {segT[tN]=ar[start]; return;}

    int mid = (start+end)/2;
    buildTree(segT,ar,start,mid,2*tN);
    buildTree(segT,ar,mid+1,end,2*tN+1);

    segT[tN]=segT[2*tN]+segT[2*tN+1];
}

int range(int* segT,int tN, int start,int end,int l,int r){

    if(l>end || r<start) return 0;
    if(l<=start && end<=r) return segT[tN];

    int mid=(start+end)/2;
    int ans1 = range(segT,2*tN,start,mid,l,r);
    int ans2 = range(segT,2*tN+1,mid+1,end,l,r); 
    return ans1+ans2;
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

void update(int* segT,int* ar,int start, int end , int idx, int val,int tN)
{
    if(start==end)
    {
        ar[idx]=val;
        segT[tN]=val;
        return;
    }
    int mid = (start+end)/2;
    if(idx<mid)
    {
        update(segT,ar,start,mid,idx,val,2*tN);
    }
    else
    {
        update(segT,ar,mid+1,end,idx,val,2*tN+1);
    }

    segT[tN]=segT[2*tN]+segT[2*tN+1];
    
    
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    // int l,r;
    // cin>>l>>r;
    int segT[4*n];
    int tN=1;
    buildTree(segT,ar,0,n-1,1);
    for(auto x: ar)cout<<x<<"\n";
    for(auto x: segT)cout<<x<<"\n";
    cout<<"answer"<<endl;
    cout<<range(segT,1,0,4,4,4);
    update(segT,ar,0,4,4,9,1);
    cout<<"updated:"<<endl;
    cout<<range(segT,1,0,4,4,4);
}