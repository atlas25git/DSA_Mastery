#include <bits/stdc++.h>
using namespace std;

string ser(string s1,string s2){
    int n1=s1.length();
    int n2= s2.length();
    if(n1!=n2)return "NO";
    
    int count[256] = {0};
     for(int i=0;i<s1.length();i++){
        count[s1[i]]++;
        count[s2[i]]--;
    }
    
    for(int i=0;i<256;i++){
        if(count[i]!=0)return "NO";
    }
    return "YES";
}


int main() {
	int t;cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s1>>s2;
	    cout<<ser(s1,s2)<<"\n";
	}
}