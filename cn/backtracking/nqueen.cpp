#include<bits/stdc++.h>
using namespace std;

//intitalizing board as a global array.
int board[11][11];

bool isPossible(int n, int r, int c)
{
    //We need to only check for the upper half,
    //as we are filling top down serially.

    //upper col
    for(int i=r-1;i>=0;i--)
    {
        if(board[i][c]==1)return false;
    }

    //upper left diag
    for(int i=r-1,j=c-1;i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]==1)return false;
    }

    //upper right diag

    for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)return false;
    }

    return true;
}

void nQueenHelper(int n, int r)
{
    if(r==n)
    {
        //print board
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<"|"<<board[i][j]<<"|";
            }
            cout<<"\n";
            
        }
        cout<<"\n";
        return;
    }

    //placing and checking for possible positions, starting with the given row. 
    for(int i=0;i<n;i++)
    {
        if(isPossible(n,r,i))
        {
            board[r][i]=1;
            nQueenHelper(n,r+1);
            board[r][i]=0;
        }
    }
    return;

}

void placeNqueen(int n)
{
    //intializing the array with 0s
    memset(board,0,11*11*sizeof(int));
    nQueenHelper(n,0);

}

int main(){
    //int n;
    //cin>>n;
    placeNqueen(4);
}