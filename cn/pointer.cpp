#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[]={1,2,3,4};
    int* p=a;
    cout<<*p++<<"\n";
    for(auto x: a)cout<<x<<" ";
    cout<<endl;
     char* y= "SARTHAK";
    for(int i=0;i<7;i++)
     cout<<*(y+i)<<"\n";

}