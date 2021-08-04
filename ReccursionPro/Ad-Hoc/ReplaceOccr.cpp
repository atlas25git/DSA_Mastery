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

//we need to locate the occrn and will have to shift chars by the len of given option

void replaceI(char a[],int i)
{
    if(a[i] == '\0' || a[i+1] == '\0')return;

    //look for the given opt
    if(a[i] == 'p' && a[i+1] == 'i'){

        //shifting + replacement
        while(a[j] != '\0')j++;
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';

    }
    else{
        replaceI(a,i+1);

    }
    return;
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