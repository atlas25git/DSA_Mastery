#include<bits10_1.h/stdc++.h>
using namespace std;

int main(){

}

void naiveFreq(int arr[], int n){

    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j= 0;j<i;j++)
            if(arr[i]==arr[j]){flag = true; break;}
        
        if(flag==true)
        continue;

        int freq = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
            freq++;


        }

        cout<<arr[i]<<" "<<freq<<endl;
    }
}