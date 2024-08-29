//Same as finding Kth from end of list done in 9 Aug session 
//link- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz

#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  // brute force approach to do this is get the node count if node count if same as n, change and delete head. Else get to the prev of 
  //node to be deleted and remove the req node. Handle edge case of deleting head

 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
     {
        ListNode*p=head,*temp;
        int i=0,k;
        while(p)
        {
            i++;
            p=p->next;
        }
        if(i==n)
        {
            temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        k=i-n;
        p=head;
        while(p)
        {
            k--;
            if(k==0) break;

            p=p->next;
        }
        temp=p->next;
        p->next=p->next->next;
        delete(temp);
        return head;

    }
};

// the optimal soln is taking a fast and slow pointer. The diff of positions bw these two will be equal to the node we have to reach. Then iterate till
//fast goes NULL and when it does the slow will be at prev of node to be deleted. Make sure to handle the condition where the node to be deleted is head
//node. In that case the fast pointer will be null due to inital positioning 


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
     {
        ListNode*fast=head,*slow=head,*temp;
        int i=0,k;
        while(n)
        {
            n--;
            fast=fast->next;
        }
         if(!fast)
        {
            temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        while(fast->next)
        {
            
            slow=slow->next;
            fast=fast->next;
        }
       
        temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
       return head;
      

    }
};