//link - https://leetcode.com/problems/reverse-linked-list/description/
// 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  //Brute force get a stacl put all elements in it and then pop it and replace in the LL

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*p=head;
        stack<int> st;
        while(p)
        {
            st.push(p->val);
            p=p->next;
        }
        p=head;
        while(p)
        {
            p->val=st.top();
            st.pop();
            p=p->next;
        }
        return head;
        
    }
};
 

 //taking three pointers and reversing
 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head,*prev=NULL,*nnode=NULL;
        
        while(curr)
        {
          nnode=curr->next;
          curr->next=prev;

          prev=curr;
          curr=nnode;
        }
    
        return prev;
        
    }
};


//Recursive solution

