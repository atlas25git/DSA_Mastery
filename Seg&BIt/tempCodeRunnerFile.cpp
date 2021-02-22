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
    if(l>=start && r<=end) return segT[tN];

    int mid=(start+end)/2;
    return (range(segT,2*tN,start,mid,l,r) + range(segT,2*tN+1,mid+1,end,l,r)); 
}

int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];
    int l,r;
    cin>>l>>r;
    int segT[4*n];
    int tN=1;
    buildTree(segT,ar,0,n-1,1);
    cout<<range(segT,tN,0,n-1,2,4);
}