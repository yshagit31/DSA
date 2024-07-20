//link- https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list
// Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Examples:

// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 3  
// Explanation: 
// After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 2 9
// Explanation:

// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

// Constraints:
// 2 <= size of the linked list(n) <= 105
// 1 <= x <= n
// 1 <= node.data <= 109

// Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = nullptr;
      prev = nullptr;
  }

};

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node*p=head;
        int cnt=0;
        if(head==NULL) return NULL;
        while(p->next)
        {
            cnt++;
            if(cnt==x) break;
            p=p->next;
        }
        Node*rear=p->prev,*front=p->next;
        if(!front&&!rear)  //pr front ==NULL and rear==NULL
        {
            delete(p);
            return NULL;
        }
        else if(!front)
        {
            rear->next=NULL;
            p->prev=NULL;
            delete p;
        }
        else if(!rear)
        {
            head=head->next;
            head->prev=NULL;
            p->next=NULL;
            free(p);
        }
        else
        {
           rear->next=front;
           front->prev=rear;
           p->next=NULL;
           p->prev=NULL;
        }
        return head;
    }
};