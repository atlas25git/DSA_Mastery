// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
map<int,int> mp; // mp hold 1 to those number which consists of only 1, 2, 3 as digits only 


 // } Driver Code Ends
//User function template for C++

//Function to find all the numbers with only 1,2 and 3 in their digits.
void findAll() {
    int num=1,num2;
    vector<int> a; int j=1;
    
    //storing 1,2, and 3 in the list.
    a.push_back(j);
    a.push_back(j+1);
    a.push_back(j+2);
    
    //The idea is to store 1 as value in a map for all numbers between 1 and
    //1000000 which have only 1,2 and 3 as digits.
    //We can then easily check for the required numbers from the map.
    mp[1]=1;
    mp[2]=1;
    mp[3]=1;
    
    j=0;
    
    //using a loop in which we keep multiplying the number in list with 10 and 
    //add 1,2 and 3 to it and store them in list one by one thus numbers 
    //with only 1,2 and 3 as digits are stored in the list.
    //This process continues till the number is less than or equal to 1000000.
    while(num<=1000000)
    {
        //storing the number from list in num2.
        num2=a[j++];//post incremrent
        
        //multiplying num2 with 10 and adding 1 and we store it in the list
        //only if it is less than or equal to 1000000.
        if((num2*10)+1<=1000000){
            a.push_back((num2*10)+1);
            //updating the value in map.
            mp[num2*10+1]=1;
        }
        //multiplying num2 with 10 and adding 2 and we store it in the list
        //only if it is less than or equal to 1000000.
        if((num2*10)+2<=1000000){
            a.push_back((num2*10)+2);
            //updating the value in map.
            mp[num2*10+2]=1;
        }
        
        //multiplying num2 with 10 and adding 3 and we store it in the list
        //only if it is less than or equal to 1000000.
        num2=(num2*10)+3;
        if(num2<=1000000){
            a.push_back(num2);
            //updating the value in map.
            mp[num2]=1;
        }
        
        //updating num which controls the loop.
        num=num2;
    }
}

// { Driver Code Starts.


int main()
{   
    findAll(); // find all such numbers whose digits are from set {1,2,3} from 1 to 1000000
    int t;
    cin>>t; 
    
    while(t--)
    {
        int n, flag=0;
        cin>>n; 
        
        int arr[n] ;
        
        for(int i=0;i<n;i++) // insert n elements
            cin >> arr[i]; 
        
        sort(arr,arr+n); // sort them
        
        for(int i = 0 ; i < n ; ++ i ) {
            if(mp[arr[i]]) { // if arr[i] is already there in the map then it satisfied else not 
                cout << arr[i] << " " ;
                flag=1;
            }
        }
        
        if(!flag)
            cout << "-1"; 
            
        cout<<endl;
    }
return 0;
}  // } Driver Code Ends