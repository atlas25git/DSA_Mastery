#include<bits/stdc++.h>


using namespace std;

int strl(char* s);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt","r",stdin);
    freopen("outout.txt","w",stdout);
    
    char str[100];
    cin>>str;
    
    cout<<strl(str)<<"\n";
}

int strl(char* s){
    if( *(s+0) == '\0')return 0;
    return 1+strl(s+1);
}