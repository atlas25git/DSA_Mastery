#include<bits/stdc++.h>
#include<sys/timeb.h>

typedef long long ll;
using namespace std;

//to calculate time
long getTimeInMicroSeconds(){
    struct timeval start;
    gettimeofday(&start,NULL);
    return start.tv_sec * 1000000 + start.tv_usec; 
}

void strlr(char* s);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt","r",stdin);
    freopen("outout.txt","w",stdout);
    
    char str[100];
    cin>>str;
    ll startTime = getTimeInMicroSeconds();
    
    strlr(str);
    ll endTime = getTimeInMicroSeconds();
    cout<<str<<" "<<startTime-endTime<<"\n";
}

void strlr(char* s){
    if( *(s+0) == '\0')return; //NULL case
    
    if(*(s+0) != 'x')strlr(s+1);
    else{
        int i=1;
        for(; *(s+i) != '\0'; i++)s[i-1]=s[i];s[i-1]=s[i];
        strlr(s);
    }
}