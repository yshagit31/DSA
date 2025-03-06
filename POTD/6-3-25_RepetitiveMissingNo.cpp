// 2965. Find Missing and Repeated Values
// Easy
// Topics
// Companies
// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
// Example 2:

// Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
// Output: [9,5]
// Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 

// Constraints:

// 2 <= n == grid.length == grid[i].length <= 50
// 1 <= grid[i][j] <= n * n
// For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
// For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
// For all x that 1 <= x <= n * n except two of them there is exatly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.


//Approach 1

// Very simple approach use a hasmap store the freq of nos. Now when freq is more than 1 that is duplcate and we will traverse the map and find all nos
//  from 1 to n^2 in map the no which is not present is the missing no 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n=grid.size();
            vector<int> ans;
            unordered_map <int,int> hash;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    hash[grid[i][j]]++;
                    if(hash[grid[i][j]]>1)
                    {
                        ans.push_back(grid[i][j]);
                    }
                }
            }
            for(int i=1;i<=(n*n);i++)
            {
                if(hash.find(i)==hash.end())
                {
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };

    // Approach 2

    // We can use a set and winsert values in it now if the insertion wont hapeen in set meaning that element is duplicate and we will find sum of all nos 
    // but duplcate no taken only once. Now subract sum of n*2 natural nos from this sum to get missing no

    //     Understanding uniq.insert(num).second in C++
    // When using unordered_set<int> uniq, the insert() function in C++ returns a pair, which contains:

    // An iterator to the inserted/found element.
    // A boolean (second) indicating whether the insertion was successful.
    // How insert(num).second Works
    // If num is not present in the set, it inserts num and returns {iterator, true}.
    // If num is already present, insertion fails, and it returns {iterator, false}.

    //     Using This in Our Code

    // if (!uniq.insert(num).second) { // If insertion fails, it's a duplicate
    //     dup = num;
    // }
    // If num is already in uniq, insert(num).second == false, meaning num is the duplicate.
    // Otherwise, num gets added, and we update currSum.

    class Solution {
        public:
            vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                int n=grid.size()*grid.size();
                 unordered_set<int>set;
                 int currSum=0;
                 int dup;
                for(auto row:grid)
                {
                    for(int num:row)
                    {
                        if(!set.insert(num).second)
                        {
                            dup=num;
                        }else{
                            currSum+=num;
                        }
                    }
                }
                int expectedSum=(n*(n+1))/2;
                int missing=expectedSum-currSum;
                return {dup,missing};
            }
        };