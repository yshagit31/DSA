// link - https://www.geeksforgeeks.org/problems/binary-search-trees/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search-trees

// Given an array of integers arr[] representing inorder traversal of elements of a binary tree. Return true if the given inorder traversal can be of a valid Binary Search Tree.

// Note - In a valid Binary Search Tree all keys are unique.

// Examples :

// Input: arr[] = [8, 14, 45, 64, 100]
// Output: True
// Input: arr[] = [5, 6, 1, 8, 7]
// Output: False
// Expected Time Complexity: O(n)

// Expected Space Complexity: O(1)

// Constraints:

// 1 <= n <= 105

// 1 <= arr[i] <= 109

#include<bits/stdc++.h>
using namespace std;

// Ques basically says inorder traversal is bst. Inorder of BST is sorted in ascending order so we are checking that

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]>=arr[i+1])
            {
                return false;
            }
        }
        
        return true;
    }
};