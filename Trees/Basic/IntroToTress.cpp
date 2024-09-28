// link - https://www.geeksforgeeks.org/problems/introduction-to-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-trees
// Given an integer i. Print the maximum number of nodes on level i of a binary tree.

// Example 1:
// Input: 5
// Output: 16
// Example 2:

// Input: 1
// Output: 1
 
// Your Task:

// Complete the function countNode() which takes an integer i as input and prints the count of maximum number of nodes at that level.

// Expected Time Complexity: O(1)

// Expected Space Complexity: O(1)

// Constraints:

// 1<=i<=20

#include<bits/stdc++.h>
using namespace std;


// soln 1 max node at any level is 2^(i-1)
class Solution {
  public:
    int countNodes(int i) {
     return pow(2,i-1);
    }

};

// Soln 2 recursion

 int countNodes(int i) {
      if(i == 1) return 1;
      return 2*countNodes(i-1);
    }

// Soln 3 Bitwise shifting any no 1 bit left is same as multiplying it by 2

 int countNodes(int i) {
      return 1<<(i-1);
    }

