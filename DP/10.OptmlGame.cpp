#include <bits/stdc++.h>
using namespace std;

int sol(int arr[],int i,int j//,int sum 
) {
    //***********************************RECURSIVE*********************************************************************
    // here we will follow the strategy of selcting theoptimal case for opponent and then substracting his 
    //sum of selectedcoins from the total sum, to get ours.
    //9999. Remember base case is the last step
    // //base case could only be if only two elements are remaining
    // if(j==i+1)return max(arr[i],arr[j]);
    
    // return max(
    //          //Case where we are slecting the i'th element, thereby letting the opp. select from i+1,j
    //          sum-ms(arr,i+1,j,sum-arr[i])
    //             ,
    //          //Case where we have selected the j'th value.
    //          sum-ms(arr,i,j-1,sum-arr[j])
    //             );
                
    //***********************************RECURSIVE SOL II*********************************************************************
    //since making a dimension for sum would be a very huge memory cost
    //base case 
    if(i+1==j)return max(arr[i],arr[j]);
    //here we are eliciting our optimized value, by playing opponents moves
    //we are going in a way that for our choice  i, we will consider opponent to choose 
    //two choices i+1, or jth term pout of whose minimum we will take since we want ours most feasible solution
    return max(
                arr[i]+min(sol(arr,i+2,j),
                            sol(arr,i+1,j-1))
                            ,
                arr[j] +min(sol(arr,i+1,j-1)
                                        
                                        ,
                                        sol(arr,i,j-2)
                
                ));
                
    
    
}

int sol(int arr[],int n)
{
     //***********************************dp*********************************************************************
    
    //   0 1 2 3        in the adj. array we consider with the starting case of i=0,j=3, starting and end indeex
    // 0  |*| |*|       and from the base condition we know i<j;
    // 1  | |*| |       this implies that the matrix is to be filled in diagonal manner
    // 2  | | |*|       we figured out the exact value  needed by analyzing the recursive calls, which for
    // 3  | | | |       0,3 wil be 0- 2,3 1,2 , 3- 1,2 , 0,1   
    
    int dp[n][n];//n is the size and easily n-1, the last array index is accesible from here
    
    //The base case where only 2 elements in array are present then we ought to return the max of two, therefor filling
    //the array for the case i+1=j, that is i,i+1;
    for(int i=0;i<n-1;i++)dp[i][i+1]=max(arr[i],arr[i+1]);
    
    //second step of filling further iterations, we observe that we are missing the diagonal value, therefore increase 
    //along j would be of 3 elements plus i, and  for subsequent array cell after skipping yet another diagonal would be 
    //3 +2, that'd be i +5;
    
    for(int gap=3;gap<n;gap+=2)
    {
        for(int i=0;i+gap<n;i++)
        {
           int j=i+gap;
            dp[i][j]= max(
                    arr[i]+min(dp[i+2][j],dp[i+1][j-1])
                    ,
                    arr[j]+min(dp[i+1][j-1],dp[i][j-2])
                );
        }
    }
    return dp[0][n-1];
}

int main(){
    // freopen("input.txt","r",stdin);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum += arr[i];
        }
        cout<<sol(arr,n)<<"\n";
    }
    return 0;
    
}