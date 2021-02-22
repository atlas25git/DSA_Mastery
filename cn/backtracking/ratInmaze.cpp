#include<bits/stdc++.h>
using namespace std;
bool flag=false;
void printSol(int** sol,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<" "<<sol[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"\n";
}

void mazehelp(int maze[][10],int n, int** sol, int x,int y)
{
    //base case
    if(x==n-1 && y==n-1)
    {
        sol[x][y]=1;
        printSol(sol,n);
        sol[x][y]=0;
        flag=true;
    }
    if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || sol[x][y]==1)
    return;

    //intializing the given co-ordinate
    sol[x][y]=1;//----actually the demarcation of path happens here.
    mazehelp(maze,n,sol,x-1,y);
    mazehelp(maze,n,sol,x+1,y);
    mazehelp(maze,n,sol,x,y-1);
    mazehelp(maze,n,sol,x,y+1);

    //all paths explored
    sol[x][y]=0;
    
}

void ratInMaze(int maze[][10], int n)
{
    int** sol = new int* [n];
    for(int i=0;i<n;i++)
    {
        sol[i]=new int [n];
    }
    //memset(sol,0,n*n*sizeof(int));
    

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sol[i][j]=0;
        }
    }
    mazehelp(maze,n,sol,0,0);

    // for(int i=0;i<n;i++)delete []sol[i];
    // delete []sol;
}

int main()
{
    freopen("output.txt","w",stdout);
    int maze [10][10]={
                       {1,1,1,0,1,0,1,0,1,0},
                       {1,1,1,1,1,1,1,1,1,1},
                       {0,0,1,1,0,0,0,0,0,0},
                       {0,0,0,1,1,0,0,0,0,0},
                       {0,0,0,0,1,1,0,0,0,0},
                       {0,0,0,0,1,1,0,0,0,0},
                       {0,0,0,0,1,1,1,0,0,0},
                       {0,0,0,1,1,1,0,1,0,0},
                       {0,0,0,0,0,1,1,1,1,0},
                       {0,0,0,0,0,0,1,1,1,1}
                       };

    ratInMaze(maze,10);
    if(!flag)cout<<"no route av.";
}