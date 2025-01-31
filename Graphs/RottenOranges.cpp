// link - https://leetcode.com/problems/rotting-oranges/description/

// 994. Rotting Oranges
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1. 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

#include<bits/stdc++.h>
using namespace std;

 int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[m][n];
        int total=0,t,cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) 
                {
                 vis[i][j]=2;  
                 q.push({{i,j},0}); 
                }
                else  vis[i][j]=0;
                if(grid[i][j]!=0)  total++;
            }
        }
        int row[]={1,-1,0,0};
        int col[]={0,0,-1,1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
             t=q.front().second;
             q.pop();
             for(int i=0;i<4;i++)
             {
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1)  // check if the grid where we are going to change are 1 or not and they shoukd not be visited
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
             }
             cnt++;
        }

        if(cnt!=total) return -1;
        return t;   
    }

    int main()
    {
        int m,n;
        cin>>m>>n;
       vector<vector<int>> grid(m, vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>grid[i][j];
            }
        }
        cout<<orangesRotting(grid); 
    }