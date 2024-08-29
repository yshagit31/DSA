//link - https://leetcode.com/problems/middle-of-the-linked-list/

// 876. Middle of the Linked List

// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 
// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100

#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//approach one - calculate length and go to middle node by counting
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*p=head; int n=0,mid;
        while(p)
        {
            n++;
            p=p->next;
        }
        mid=(n/2);
        p=head;
        while(mid>0)
        {
            mid--;
            p=p->next;
        }
        return p;
        
    }
};

//approach two tortoise and hare

   ListNode* middleNode(ListNode* head) {
        ListNode*slow=head,*fast=head; 
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;  
    }