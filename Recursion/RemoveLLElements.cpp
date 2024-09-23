//link - https://leetcode.com/problems/remove-linked-list-elements/?envType=problem-list-v2&envId=recursion

// Sept 23 session - Q2
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Example 1:

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]
// Example 2:

// Input: head = [], val = 1
// Output: []
// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    void Remove(ListNode* &head, int val)
    {
        if(head==NULL) return;
         if(head->val==val) 
        {
            ListNode*temp=head;
            head=head->next;
            delete(temp);
            Remove(head,val);
        } 
        else Remove(head->next,val);
    }

    ListNode* removeElements(ListNode* head, int val)
     {
        Remove(head, val);
        return head;
    }
};

//approach 2

 ListNode* removeElements(ListNode* head, int val)
     {
         if(head==NULL) return NULL;
         head->next=removeElements( head,val);
         if(head->val==val)
         {
            
         }
        return head;
    }
