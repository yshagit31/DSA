// link - https://leetcode.com/problems/insert-into-a-binary-search-tree/

// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

// Example 1:

// Input: root = [4,2,7,1,3], val = 5
// Output: [4,2,7,1,3,5]
// Explanation: Another accepted tree is:

// Example 2:

// Input: root = [40,20,60,10,30,50,70], val = 25
// Output: [40,20,60,10,30,50,70,null,null,25]
// Example 3:

// Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
// Output: [4,2,7,1,3,5]
 
// Constraints:

// The number of nodes in the tree will be in the range [0, 104].
// -108 <= Node.val <= 108
// All the values Node.val are unique.
// -108 <= val <= 108
// It's guaranteed that val does not exist in the original BST.


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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
             root= new TreeNode(val); 
             return root;
        }
        TreeNode* temp,*prev=root;
        temp=root;

        //traverse to the node you will have to insert also keep prev so that if present in null we have to add in prev
        while(root)
        {
            if(root->val<val)
            {
                prev=root;
                root=root->right;
            }
            else if(root->val >val)
            {
                prev=root;
                root=root->left;
            }
        }

        TreeNode *nnode= new TreeNode(val);
        if(root) // if root not null we add in that
        {
        if(val>root->val)   root->right=nnode;
        else   root->left=nnode;
        }
        else{  // if root is null means we have to add in prev
              if(val>prev->val)   prev->right=nnode;
        else   prev->left=nnode;
        }
        return temp;
    }
};

// Approach 2 jaise mai soch raha tha ki comparison krne ke bad break laga dete agar left ya right null to break ki jagah waha insert kr rahe directly kyunki null
// tabhi hoga jab hum destination pahuch chuke honge

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(root==NULL) return new TreeNode(val);
     TreeNode *temp=root;
     while(true)
     {
        if(temp->val>val)
        {
            if(!temp->left) 
            {
                temp->left=new TreeNode(val);
                return root;
            }
            temp=temp->left;
        }
        else{
            if(!temp->right)
            {
                temp->right=new TreeNode(val);
                return root;
            }
            temp=temp->right;
        }
     }
    }
};