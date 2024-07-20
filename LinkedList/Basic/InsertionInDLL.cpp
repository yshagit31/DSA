//link - https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

// Doubly linked list Insertion at given position
// Difficulty: BasicAccuracy: 47.13%Submissions: 93K+Points: 1
// Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.

// Example 1:

// Input:
// LinkedList: 2<->4<->5
// p = 2, x = 6 
// Output: 2 4 5 6
// Explanation: p = 2, and x = 6. So, 6 is
// inserted after p, i.e, at position 3
// (0-based indexing).
// Example 2:

// Input:
// LinkedList: 1<->2<->3<->4
// p = 0, x = 44
// Output: 1 44 2 3 4
// Explanation: p = 0, and x = 44 . So, 44
// is inserted after p, i.e, at position 1
// (0-based indexing).
// Your Task:
// The task is to complete the function addNode() which head reference, position and data to be inserted as the arguments, with no return type.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N <= 104
// 0 <= p < N

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};


//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
       Node*p=head;int cnt=0;
       while(p->next)
       {
           if(pos==cnt)
           {
          break;
           }
           cnt++;
           p=p->next;
         
       }
           Node*temp=new Node(data);
       if(p->next==NULL)
       {
           temp->prev=p;
           p->next=temp;
       }
       else{
           p->next->prev=temp;
           temp->next=p->next;
           temp->prev=p;
           p->next=temp;
       }
 
}