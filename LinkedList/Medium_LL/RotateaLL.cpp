//9 Aug LL session ques 4
//https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1?page=1&category=Linked%20List&difficulty=Medium&sortBy=submissions

// Given the head of a singly linked list, the task is to rotate the linked list clockwise by k nodes, i.e., left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

// Examples:

// Input: linkedlist: 2->4->7->8->9 , k = 3
// Output: 8->9->2->4->7
// Explanation:
// Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
// Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
// Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

// Input: linkedlist: 1->2->3->4->5->6->7->8 , k = 4
// Output: 5->6->7->8->1->2->3->4

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= number of nodes <= 103
// 1 <= node -> data <= 104
// 1 <= k <= number of nodes 

//get a pointer to the last of node and a pointer to the node whose next we have to make the new head
//join last node and start node then if the p pointer next is null mean we are at last node means we have to swap all the elements in that case we return
// head as it is otherwise we make necessary link changes

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
    Node* rotate(Node* head, int k) {
        Node*last=head,*p=head,*start=head;
        while(last->next)
        {
            last=last->next;
        }
        for(int i=1;i<k;i++)
        {
            p=p->next;
        }
         if(p->next)
         {
             head=p->next;
             p->next=NULL;
             last->next=start;
          }
        return  head;
    }
};



