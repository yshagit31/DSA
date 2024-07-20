//link - https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-linked-list-1664434326
// Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

// Example:
// Input:
// n = 4
// 1->2->3->4
// Key = 3
// Output:
// True
// Explanation:
// 3 is present in Linked List, so the function returns true.
// Your Task:
// Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value by checking the key is present or not in the linked list.

// Constraint:
// 1 <= n <= 105
// 1 <= key <= 105

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        Node*p=head;
        while(p)
        {
            if(p->data==key) return true;
            else p=p->next;
        }
        return false;
    }
};

