// 3208. Alternating Groups II
// Hint
// There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

// Example 1:

// Input: colors = [0,1,0,1,0], k = 3

// Output: 3

// Explanation:

// Alternating groups:

// Example 2:

// Input: colors = [0,1,0,0,1,0,1], k = 6

// Output: 2

// Explanation:

// Alternating groups:

// Example 3:

// Input: colors = [1,1,0,1], k = 4

// Output: 0

// Explanation:

// Constraints:

// 3 <= colors.length <= 105
// 0 <= colors[i] <= 1
// 3 <= k <= colors.length


// Gives tle brute force

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt=0,flag,n=colors.size();
        for(int i=0;i<colors.size();i++)
        {
            flag=0;
            for(int j=0,l=i; j<k-1; j++,l++)
            {
                if(colors[l%n]==colors[(l+1)%n]) 
                { 
                    flag=1;
                    break;
                    }
            }
            if(flag==0) cnt++;       
        }
        return cnt;
    }
};

// sliding window 

class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int cnt=0,n=colors.size(),left=0,limit=n+k-1;
            while(left<n)
            {
                    int right=left+1;
                    while(right<limit && colors[(right-1)%n]!=colors[(right)%n]) 
                        right++;
                    if(right-left>=k)
                    {
                        cnt+=(right-left)-k+1;
                    }
                    left=right;
            }
            return cnt;
        }
    };