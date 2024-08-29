//link - https://leetcode.com/problems/odd-even-linked-list/description/
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
// Note that the relative order inside both the even and odd groups should remain as it was in the input.
// You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:
// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]
 
// Constraints:

// The number of nodes in the linked list is in the range [0, 104].
// -106 <= Node.val <= 106


//   Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


//Brute force solution
// Iterate the list two times and add the odd elements in a vector first time then second time add the even nos in the vector. 
// Iterate the list again and replace the values with the vector elements.

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return head;
        ListNode*p=head;
        vector <int> arr; int i;
        while(p&&p->next)
        {
            arr.push_back(p->val);
            p=p->next->next;
        }
        if(p) arr.push_back(p->val);

    //reinitialising p
        p=head->next;
          while(p&&p->next)
        {
            arr.push_back(p->val);
            p=p->next->next;
        }
        if(p) arr.push_back(p->val);

        p=head,i=0;
        while(p)
        {
            p->val=arr[i];
            p=p->next;
            i++;
        }
        return head;
    }
};


//Approach second
//we'll change the link of the nodes, we'll connect odd nodes to each other and even to each other. And then we'll connect odd last to even first

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return head;

       ListNode*odd=head,*even=head->next,*evenHead=head->next;
        //evenHead to get first even element to join with odd last as it wont be accessible later

       while(even!=NULL&&even->next!=NULL) //even will always be ahead so even null
       {
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
       }

       //connecting odd last to even first
       odd->next=evenHead;
        return head;
    }
};