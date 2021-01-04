#include<bits/stdc+.h>
typedef long long ll;
using namespace std;
//checking will involve n iterations, therefore total t.c. = NlogD;
bool check(int cows,int pos[],int n,ll dis){
    int count=1;
    ll last_position = pos[0];
    for(int i=1;i<n;i++){
        if(pos[i]-last_position >= dis){
            last_position=pos[i];
            count++
        }
        if(count==cows)return true;
    }
    return false;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        ll pos[n];
        for(int i=0;i<n;i++){
            cin>>pos[i];
        } 
        sort(pos,pos+n);
        ll start = 0;
        ll end = pos[n-1]-pos[0];
        ll ans =-1;
        //this will take logD time;
        while(start<=end){
            ll mid = start +(end-start/2);
            if(check(c,pos,n,mid)){
                ans=mid; 
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}