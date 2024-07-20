
//link - https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

// Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

// Examples :

// Input: LinkedList: 1->2->3->4->5 , x = 6
// Output: 1->2->3->4->5->6
// Explanation: 

// We can see that 6 is inserted at the end of the linkedlist.
// Input: LinkedList: 5->4 , x = 1
// Output: 5->4->1
// Explanation: 

// We can see that 1 is inserted at the end of the linkedlist.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= number of nodes <= 105
// 1 <= node->data , x <= 103


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node *temp=new Node(x);
        if(head==NULL) {
            head=temp;
            return head;
        }
        Node*p=head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
    return head;
    }

};


