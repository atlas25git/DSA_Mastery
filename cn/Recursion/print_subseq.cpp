#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int sub(string s,string* op)
{
    if(s.empty())
    {
        op[0]="";
        return 1;
    }
    int count = sub(s.substr(1),op);
    //assuming the abv fn call will fill the op with all possible subsequences of remaining s,i.e, s- s[0];
    //here applying our algo
    for(int i=0;i<count;i++)
    {
        op[count + i]= op[i]+s[0];
    }
    return count*2;
}

void print_sub(string s, string op){

    //basecase:all the cases considered.

    if(s.empty())
    {
        cout<<op<<"\n";
        return;
    }
    // fn call for the case : considering first element
    print_sub(s.substr(1),op+s[0]);
    //fn call for the case : not considering first element
    print_sub(s.substr(1),op);
}

int main(){
    freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    string* op = new string[1000];
    string op1="";
    int count = sub(s,op);
    for(int i=0;i<count;i++)cout<<op[i]<<endl;
    

    cout<<count<<"\n";
    print_sub(s,op1);
}