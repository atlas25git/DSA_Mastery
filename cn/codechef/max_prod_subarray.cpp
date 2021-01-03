#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll kss(int* ar, int n){
    int cs= 0;
    int ms= INT_MIN;

    for(int i=0;i<n;i++){
        cs+=ar[i];
        ms= max(cs,ms);
        cs<0?cs=0:cs=cs;
    }
    return ms;

}

ll msa(int* ar,int n,int k){
    ll ks = kss(ar,n);
    if(k==1){
        return ks;
    }
    ll css=0,cps=0;
    ll mss=INT_MIN,mps=INT_MIN;
    //computing css, and also since css covers all the elements it will also be equal to ts.

    for(int i=0;i<n;i++){
        css+=ar[i];
        mss=max(mss,css);
    }
    ll ts = css;
    
    for(int i=n-1;i>=0;i--){
        cps+=ar[i];
        mps=max(mps,cps);
    }
    ll ans;
    ts<0? ans=max(mps+mss,ks):ans= max(ks,mps+mss+(k-2)*ts);
    return ans;
}
ll maxend(int* ar,int n){

    int maxi = 1;
    int mini = 1;
    int msf = 0;
     for(int i=0;i<n;i++)
     {
         if(ar[i]>0){
             maxi *= ar[i];
         }
         else if(ar[i]==0){
             maxi=0;
             mini=1;
         }
         else{
             int temp = maxi;
             maxi = max(mini*ar[i],1);
             mini = temp*ar[1];
         }
         msf=max(msf,maxi);
     }

     return msf;
}
int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k; cin>>n>>k;
        int ar[n];
        for(int i=0;i<n;i++)cin>>ar[i];
        cout<<msa(ar,n,k)<<"\n";
        cout<<maxend(ar,n)<<"\n";
        
    }
    
}
