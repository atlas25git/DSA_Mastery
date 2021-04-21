#include <bits/stdc++.h>
using namespace std;

int iPartition(int arr[], int l, int h)
{   
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    //here i+1 signifies the partition's end.
    swap(arr[i+1],arr[h]);
    return i+1;
}
 
int main() {
	
    int arr[]={10,80,30,90,40,50,70};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	iPartition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}