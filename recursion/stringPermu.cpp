#include<bits/stdc++.h>

using namespace std;

int subs(string s,string* op);
void subsPrint(string s, string op);

int main(){
    string output[20];
    string s ="sarthak";
    string op;
    subsPrint(s,op);
    //cout<<subs(s,output);
    //for(auto x: output)cout<<x<<endl;
}

int subs(string s,string* op)
{
    if(s.length()==0)
    {
        op[0]=" ";
        return 1;
    }
    int opsize = subs(s.substr(1),op);

    for(int i=0;i<opsize;i++)
    {
        op[i+opsize]=s[0]+op[i];
    }

    return 2*opsize;
}

void subsPrint(string s, string op)
{
    if(s.length()==0){cout<<op<<"\n";return;}
    //first char not considered
    subsPrint(s.substr(1),op);
    //first char considered
    subsPrint(s.substr(1),op+s[0]);

}