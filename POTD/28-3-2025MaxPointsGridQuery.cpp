// link - https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28

// 2503. Maximum Number of Points From Grid Queries

// You are given an m x n integer matrix grid and an array queries of size k.

// Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

// If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
// Otherwise, you do not get any points, and you end this process.
// After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

// Return the resulting array answer.

 

// Example 1:


// Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
// Output: [5,8,1]
// Explanation: The diagrams above show which cells we visit to get points for each query.
// Example 2:


// Input: grid = [[5,2,1],[1,1,2]], queries = [3]
// Output: [0]
// Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 1000
// 4 <= m * n <= 105
// k == queries.length
// 1 <= k <= 104
// 1 <= grid[i][j], queries[i] <= 106]

#include<bits/stdc++.h>
using namespace std;

class Solution {
    #define pii pair<int,int>
    #define pip pair<int,pii>
   int isValid(int &m,int &n, int &x, int &y)
   {
       return (x>=0 && x<m&& y>=0 && y<n);
   }
   public:
       vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
   
           priority_queue<pip, vector<pip> , greater<pip>> minHeap;
           unordered_map<int,int> queryCount;
           int m=grid.size(),n=grid[0].size();
           vector<vector<int>> vis(m,vector<int>(n,0));
           minHeap.push(make_pair(grid[0][0],make_pair(0,0)));
                   // minheap.push(make_pair(grid[0][0],make_pair(0,0)));
           vis[0][0]=1;
           set<int>sortedQuery(queries.begin(),queries.end());
               vector<int> dir={-1,0,1,0,-1};
           int k=queries.size(),count=0;
           for(int query:sortedQuery)
           {
               while(!minHeap.empty())
               {
                   pip curr=minHeap.top();
                   minHeap.pop();
                   int ele=curr.first;
                   int x=curr.second.first;
                   int y=curr.second.second;
                   if(ele>=query)
                   {
                   minHeap.push(curr);
                   break;
                   }
                   count++;
                   for(int i=0;i<4;i++)
                   {
                       int newX=x+dir[i];
                       int newY=y+dir[i+1];
                       if(isValid(m,n,newX,newY) && !vis[newX][newY])
                       {
                           vis[newX][newY]=1;
                           minHeap.push(make_pair(grid[newX][newY],make_pair(newX,newY)));
                       }
                   }
   
               }
               queryCount[query]=count;
           }
       vector<int> ans;
           for(int i=0;i<k;i++)
           {
               ans.push_back(queryCount[queries[i]]);
           }
   
           return ans;
       }
   };