#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

//here we are saving the nlog(n) time involved everytime to sort by using a queue of elements that have been worked upon.

int main(){
    // freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    queue<ll> q;
    int count_m = 0;
    int ep = n-1;
    while (m--)
    {
        int curr_m;cin>>curr_m;
        int ans;

        for(;count_m<curr_m;count_m++)
        {
            if(ep>=0 && (q.empty() || arr[ep] >= q.front())){
                ans = arr[ep];
                ep--;
            }
            else{
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
