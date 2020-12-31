#include<bits/stdc++.h>

using namespace std;

int cd(int arr[],int n){
    unordered_set<int>s(arr,arr+n);
    return s.size();
}