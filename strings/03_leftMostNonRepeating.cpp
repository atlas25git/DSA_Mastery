#include <bits/stdc++.h>
using namespace std;

const int CHAR=256;
int ser(string &str) 
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fI[i]>=0)res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    string s;cin>>s;
	    int res=ser(s);
	    res==-1?cout<<"-1"<<"\n":cout<<s[res]<<"\n";
	}
}