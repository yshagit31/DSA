// Given a n*m matrix and the cells of matrix are balck or white. A string is symmetric if it is same when seen from reverse. For eg "BCCB" is symmetric and "BCCC" is not
// Return the minimum no of steps in which the matrix will become symmetric 

// I/P - ["BWBWWB"]

//3240. Minimum Number of Flips to Make Binary Grid Palindromic II

// You are given an m x n binary matrix grid.

// A row or column is considered palindromic if its values read the same forward and backward.

// You can flip any number of cells in grid from 0 to 1, or from 1 to 0.

// Return the minimum number of cells that need to be flipped to make all rows and columns palindromic, and the total number of 1's in grid divisible by 4.



// Example 1:

// Input: grid = [[1,0,0],[0,1,0],[0,0,1]]

// Output: 3

// Explanation:

// Example 2:

// Input: grid = [[0,1],[0,1],[0,0]]

// Output: 2

// Explanation:


// Example 3:

// Input: grid = [[1],[1]]

// Output: 2

// Explanation:


// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m * n <= 2 * 105
// 0 <= grid[i][j] <= 1

#include<bits/stdc++.h>
using namespace std;
// not fully working yet
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
       int m=grid.size(),n=grid[0].size();
       int cnt=0;
        for( int r=0;r<m;r++)
        {
            int left=0, right=n-1;
           while(left<=right)
           {
            if(grid[r][left]!=grid[r][right])
            {
                cnt++; 
            }
            left++,right--;
           }
        }
        for(int r=0;r<n;r++)
        {
            int left=0, right=m-1;
           while(left<=right)
           {
            if(grid[left][r]!=grid[right][r])
            {
                cnt++; 
            }
            left++,right--;
           }
        }
        return cnt;
    }
};