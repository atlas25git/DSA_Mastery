#include<bits/stdc++.h>

using namespace std;

void lexo(string currStr,string MainStr, int N, int M)
{
    if(N==M)
    {
        cout<currStr<<endl;
        return;
    }
    for(int i = 0;i < MainStr.length(); i++)
    {
        lexo(currStr+MainStr[i],MainStr.substr(i,MainStr.length()+1),N+1,M);
    }
}
int main()
{
    string MainStr= "aeiou";
    int N,count = 0;
    cin >> N;
    lexo("",MainStr,0,N);
    return 0;
}