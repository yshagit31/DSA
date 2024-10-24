// link - https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

// Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

// Example 1:

// Input:
//            5
//          /    \
//         4      6
//        /        \
//       3          7
//      /
//     1
// Output: 1
// Example 2:

// Input:
//              9
//               \
//                10
//                 \
//                  11
// Output: 9
// Your Task:
// The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST. If the tree is empty, there is no minimum element, so return -1 in that case.

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= n <= 104

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Move to the leftest possible node
class Solution {
  public:
    int minValue(Node* root) {
        int minVal;
      while(root!=NULL)
     {
         minVal=root->data;
         root=root->left;
         
     }
     return minVal;
    }
};
