#include<bits/stdc++.h>
using namespace std;

void lexo(string currS,string mainS,int n,int m,int& z)
{
    //base case
    if(n==m)
    {   z++;
        cout<<currS+" "<<z<<"\n";
        
        return;
    }
    for(int i=0;i<mainS.length();i++)
    {
        lexo(currS+mainS[i],mainS.substr(i),n+1,m,z);
    }

}

int main()
{   int y=0;
     int& z=y;
    lexo("","aeiou",0,1,z);
    return 0;
}



