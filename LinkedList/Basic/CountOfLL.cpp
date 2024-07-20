//link -https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-nodes-of-linked-list

// Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

// Examples :

// Input: LinkedList : 1->2->3->4->5
// Output: 5
// Explanation: Count of nodes in the linked list is 5, which is its length.

// Input: LinkedList : 2->4->6->7->5->1->0
// Output: 7
// Explanation: Count of nodes in the linked list is 7. Hence, the output is 7.
// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data <= 103

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
    int getCount(struct Node* head) 
    {
        int count=0;
        Node*p=head;
        while(p)
        {
            count++;
            p=p->next;
        }
        return count;
    }
};


