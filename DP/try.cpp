#include<bits/stdc++.h>
using namespace std;

int getK(int n, int c)
{
    if(n<c) return 0;
    return 1+getK(n-c, c+1);
}

int getCount0(int* arr,int n)
 {  
     int c=0;
     for(int i=0;i<n;i++){
         if(arr[i]==0)c++;
     }
     return c;
 }

int findk(int* arr, int n)
{
    int posK = getK(n,1);
    int getCountZ = getCount0(arr,n);
    int getCountO = n-getCountZ;  

    if(getCountZ < n-getCountZ) return n-getCountZ;
    else return getCountZ;
}

int main()
{
    int n = 2;
    int arr[2] = {0,1};
    cout<<findk(arr,n);
}

