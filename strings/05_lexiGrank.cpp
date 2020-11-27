#include<bits/stdc++.h>
using namespace std;

int fact(int n){

if(n==0||n==1)return 1;
else return n*fact(n-1);
}
int lrank(string s){
    int res=1;
    int n=s.length();
    int mul=fact(n);
    int count[256]={0};
    for(int i=0;i<n;i++)
        count[s[i]]++;
    for(int i=1;i<256;i++)
        count[i]+=count[i-1];
    // for(int i=0;i<256;i++)
    //     if(count[i]!=0)cout<<count[i]<<"\n";
    for(int i=0;i<n;i++)
    {   //way to write factorial for subsequently decreasing places.
        mul=mul/(n-i);

        
        res+=count[s[i]-1]*mul;
        //reduceing the cumulative count for the other upcoming charachters
        //the ones after the present charachter's freq. will be subsequently reduced.
        for(int j=s[i];j<256;j++)
            count[j]--;
    }
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    string s;cin>>s;
    cout<<lrank(s);
}