// link - https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Example:

// Input:
// n = 7               2
//                      \
//                       81
//                     /     \
//                  42       87
//                    \       \
//                     66      90
//                    /
//                  45
// x = 87
// Output:
// 87
// Explanation:
// 87 is present in tree so floor will be 87.
// Example 2:

// Input:
// n = 4                     6
//                            \
//                             8
//                           /   \
//                         7       9
// x = 11
// Output:
// 9
// Your Task:-
// You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and integer x returns the floor value.

// Constraint:
// 1 <= Noda data <= 109
// 1 <= n <= 105

// Expected Time Complexity: O(height of tree)
// Expected Space Complexity: O(height of tree)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

class Solution{

public:
    int floor(Node* root, int x) {
       int floor=-1;
       while(root)
       {
           if(root->data==x)
           {
              return floor=root->data;
           }
           else if(root->data<x)
           {
               floor=root->data;
               root=root->right;
           }
           else
           {
               root=root->left;
           }
       }
           return floor;
    }
};