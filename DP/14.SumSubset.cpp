#include<bits/stdc++.h>

using namespace std;

int sumss(int s, int * arr, int n){

    if(n==0)
        return sum ==0 ? 1:0;
    return sumss(s,arr,n-1) // forming the subset w/o considering the last element
                 + sumss(s-arr[n-1],arr,n-1);

}

int main(){
    int t;cin>>t;
    while(t--){
        int n,s;cin>>n>>s;int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<sumss(s,arr,n)<<"\n";
    }
}