// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        //if length of string p is greater than string s then we return -1.
        if(p.length()>s.length())
        {
            return "-1";
        }
        else
        {
            //using hash tables to store the count of characters in strings.
            int shash[26]={0};
            int phash[26]={0};
            
            //storing the count of characters in string p in hash table.
            for(int i=0;i<p.length();i++)
            {
                phash[p[i]-'a']++;
            }
            
            int counter=0;
            int begin=0;
            int startindex=-1;
            int length=0;
            int minlength=INT_MAX;
            for(int i=0;i<s.length();i++)
            {
                //storing the count of characters in string s in hash table.
                shash[s[i]-'a']++;
                
                //if count of current character in string s is equal to or less 
                //than in string p, we increment the counter.
                //if count in shash becomes greater than in phash 
                //it denotes that for those s[i]s count has already been
                //increased
                if(phash[s[i]]-'a'!=0&&shash[s[i]-'a']<=phash[s[i]-'a'])
                {
                    counter++;
                }
                
                //if all the characters are matched
                if(counter==p.length())
                {
                    //we try to minimize the window.
                    while(shash[s[begin]-'a']>phash[s[begin]-'a']||phash[s[begin]-'a']==0)
                    {
                        if(shash[s[begin]-'a']>phash[s[begin]-'a'])
                        shash[s[begin]-'a']--;
                        begin++;
                    }
                    //updating window size.
                    length=i-begin+1;
                    if(length<minlength)
                    {
                        //if new minimum sub-string is found, we store value
                        //of its starting index for new found window.
                        startindex=begin;
                        minlength=length;
                    }
                    
                }
            }
            
            //returning the smallest window or -1 if no such window is present.
            if(startindex==-1)
                return "-1";
            else
                return s.substr(startindex,minlength);
        }
    }
};;

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends