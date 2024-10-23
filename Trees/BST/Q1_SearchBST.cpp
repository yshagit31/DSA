// link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/

// 700. Search in a Binary Search Tree

// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Example 1:

// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]
// Example 2:

// Input: root = [4,2,7,1,3], val = 5
// Output: []
 
// Constraints:

// The number of nodes in the tree is in the range [1, 5000].
// 1 <= Node.val <= 107
// root is a binary search tree.
// 1 <= val <= 107


#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// we have to search while root is null or we get the value
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL &&root->val!=val)
        {
            if(root->val<val)
            {
              root=root->right;  
            }
            else{
                root=root->left;
            }
        }
        return root;
    }
};