// link - https://leetcode.com/problems/balanced-binary-tree/description/

// Given a binary tree, determine if it is 
// height-balanced 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


//incorrect

int height(Node* root)
    {
        if(root==NULL) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        return 1+max(lh,rh);
    }
    
    bool isBalanced(Node *root)
    {
        if(root==NULL) return false;
        
        if(abs(height(root->left)-height(root->right))>1) return false;
        
        return true;
        
    }

//Optimised approach

class Solution{
    public:
    int height(Node* root)
    {
        if(root==NULL) return 0;
        
        int lh=height(root->left);
        if(lh==-1) return -1;
        int rh=height(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        
        return 1+max(lh,rh);
    }
    
    bool isBalanced(Node *root)
    {
       return height(root)!=-1 ;
        
    }
};

