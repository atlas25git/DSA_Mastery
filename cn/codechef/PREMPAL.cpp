#include<bits/stdc++.h>
using namespace std;

char getChar(int i){
    return (char)(i+97);
}

void pall(string s){
    map<char,vector<int> > im;
    for(int i=0;i<s.length();i++){
        im[s[i]].push_back(i);
    }
    int odd_freq = 0;
    for(int i=0;i<26;i++){
        if((im[getChar(i)].size() % 2 )!= 0){
            odd_freq++;
        }
    }
    if(odd_freq>=2){
        cout<<"-1";
        return;
    }
    int ans[s.length()];
    int start =0;
    int end = s.length() - 1;

    for(int i=0;i<26;i++){
        char currentChar = getChar(i);
        for(int j=0;j<im[currentChar].size(); j+=2){
            if((im[currentChar].size()-j)==1)
            {
                ans[s.length()/2] = im[getChar(i)][j];
                continue;
            }
            
                ans[start]= im[currentChar][j];
                ans[end]= im[currentChar][j+1];
                start++;
                end--;
            }
        }
        for(int i=0;i<s.length();i++){
            cout<<ans[i]+1<<" ";
        }
        return;
    }


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        pall(s);
        cout<<"\n";
    }
}