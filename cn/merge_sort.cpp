#include<bits/stdc++.h>
using namespace std;

void copy(int ar[],int s[],int l,int r)
{   int k =0;
    for(int i=l;i<=r;i++)
        s[k++]=ar[i];
}

void merge(int* ar, int l ,int m, int r)
{
    int s1[m-l+1]; int s2[r-m];
    copy(ar,s1,l,m);
    copy(ar,s2,m+1,r);

    int i=0,j=0;
    int k=l;


    while(i<(m-l+1) && j<(r-m))
    {
        if(s1[i]<=s2[j])
        {   //here the case for equal elements will be handled in the subsequent
            //next iteration as the next element of s1 will definitely be greater
            //hence placing the dupicate alongwith its doppleganger.
            ar[k++]=s1[i++];
        }
        else
        {
            ar[k++]=s2[j++];
        }
        
    }
    //the remanants will only be in one list
    //therefore they will also be sorted ones
    //hence we could copy them blatantly.
    while(i<(m-l+1))
    {
        ar[k++]=s1[i++];
    }

    while(j<(r-m))
    {
        ar[k++]=s2[j++];
    }

}

void sort(int* ar, int l, int h)
{   
    //base case on this condn, merging will start
    if(h<=l)return;

    int mid = (l+h)/2;
    sort(ar,l,mid);
    sort(ar,mid+1,h);
    merge(ar,l,mid,h);
}

int main(){
    int ar[]={9,8,7,6,5,4,3,2,1,0};
    sort(ar,0,9);
   
    for(int i=0;i<10;i++)cout<<ar[i]<<"\n";
}