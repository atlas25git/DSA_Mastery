/***************************************
*****Solution authored by Atlas25.******
*****************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
const int mod = 1e9 + 7;
const int N = 100005, M=22;

int firstOcc(int *a,int n,int key)
{
    if(n==0)return -1;

    if(a[0] == key)return 0;

    int i = firstOcc(a+1,n-1,key);
    if(i==-1)return -1;
    
    return i+1;

}

int allOccr(int *a,int i,int n,int key)
{
    if(i==n)return;

    if(a[i]==key)cout<<i<<" ";

    return allOccr(a,i+1,n,key);
}

void solve(){
    int i,j,k,n,m,ans=0,cnt=0,sum=0;
        
}
void init() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int32_t main(){
    init();
        {
            int t;
            cin>>t;
            while(t--)
            solve();
        }
    }