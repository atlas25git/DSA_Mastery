// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to sort vector elements first according to time and if time is
    //same for two events, then arrival comes first followed by departure.
    static bool customsort(const pair<int,char> &a,const pair<int,char> &b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector< pair<int,char> > order;
        
        //inserting all the values of time(arrival and departure)
        //in the vector of pairs.
        for (int i = 0; i < n; i++) {
    
            //if the time is of arrival then we keep second value
            //of pair as 'a' else 'd'.
            order.push_back(make_pair(arr[i], 'a'));
            order.push_back(make_pair(dep[i], 'd'));
        }
    
        //using custom sort vector, first according to time and if time is
        //same for two events, then arrival comes first followed by departure.
        sort(order.begin(),order.end(),customsort);
    
        int result = 1;
        int plat_needed = 0;
        
        //using an iterator on vector of pairs.
        vector< pair<int,char> >::iterator it = order.begin();
    
        for (; it != order.end(); it++) {
            //if the second value of vector element is 'a' which stands
            //for arrival then we add 1 to platform needed else we 
            //subtract 1 from platform needed.
            if ((*it).second == 'a')
                plat_needed++;
            else
                plat_needed--;
            
            //we keep updating the value of result.
            if (plat_needed>result)
                result = plat_needed;
        }
        //returning the minimum number of platforms required.
        return result;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends