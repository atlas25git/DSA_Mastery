// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	string temp = "";
    	int sum = 0;
    
    	//iterating over the string.
    	for (char ch: str)
    	{
    		//if current character is digit, we store it in a temporary string.
    		if (isdigit(ch))
    			temp += ch;
    		else
    		{
    			//incrementing final sum by number stored in temporary string.
    			sum += atoi(temp.c_str());
                //making the temporary string empty again.
    			temp = "";
    		}
    	}
        //adding any number if it's present in temporary
    	//string to final sum and returning it.
    	return sum + atoi(temp.c_str());
    }

};

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends