//link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
// 2095. Delete the Middle Node of a Linked List

// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 
// Example 1:

// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node. 
// Example 2:

// Input: head = [1,2,3,4]
// Output: [1,2,4]
// Explanation:
// The above figure represents the given linked list.
// For n = 4, node 2 with value 3 is the middle node, which is marked in red.
// Example 3:

// Input: head = [2,1]
// Output: [2]
// Explanation:
// The above figure represents the given linked list.
// For n = 2, node 1 with value 1 is the middle node, which is marked in red.
// Node 0 with value 2 is the only node remaining after removing node 1.

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 1 <= Node.val <= 105

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  // Brute force count LL and move to a node prior to the middle node and delete
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *p=head,*temp;
        int n=0,mid;
        while(p)
        {
            n++;
            p=p->next;
        }
        mid=n/2;
        p=head;
        while(mid>1)
        {
            mid--;
            p=p->next;
        }
        temp=p->next;
        p->next=p->next->next;
        delete(temp);
        return head;   
    }
};

// Striver brute force

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *p=head,*temp;
        int n=0,mid;
        while(p)
        {
            n++;
            p=p->next;
        }
        mid=n/2;
        p=head;
        while(p)
        {
            mid--;
            if(mid==0)  //checking while decrementing before taking p ahead
            {
                temp=p->next;
                p->next=p->next->next;
                delete(temp);
                break;
            }
            p=p->next;
        }

        return head;   
    }
};

// Optimal tortoise and hare method. We have to get slow one step before middle to first we move fast once out of the loop without moving slow and move simultaneously

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head==NULL||head->next==NULL) return NULL;
        ListNode *slow=head,*fast=head,*temp;

        fast=fast->next->next;

        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
                temp=slow->next;
                slow->next=slow->next->next;
                delete(temp);

        return head;   
    }
};