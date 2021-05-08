// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
		int n = nums.size();
		
		//creating a list of pairs where first element of pair is array 
        //element and second element is its position.
		vector<pair<int,int>>cur(n);
		
		//iterating over the array elements.
		for(int i = 0; i < n; i++)
		{
		    //storing the elements and their position as pair in the list.
			cur[i].first = nums[i];
			cur[i].second = i;
		}
		//sorting the list.
		sort(cur.begin(), cur.end());
		
		//using boolean list to mark visited elements and currently 
        //marking all the nodes as false.
		vector<bool>vis(n, false);
		int ans = 0;
		
		for(int i = 0; i < n; i++)
		{
		    //if element is already visited or it is already at
		    //correct position, we continue the loop.
			if(vis[i] or cur[i].second == i)
				continue;
			int cycle_size = 0;
			int j = i;
			
			//while element is not visited, we find out the number of nodes in
            //this cycle and keep incrementing cycle size.
			while(!vis[j]){
				vis[j] = true;
				j = cur[j].second;
				cycle_size++;
			}
			//updating number of swaps required.
			ans += (cycle_size > 1) ? cycle_size - 1 : 0; 
		}
		return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends