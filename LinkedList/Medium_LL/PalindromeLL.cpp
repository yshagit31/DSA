////9 Aug LL session ques 6
//https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1?page=1&category=Linked%20List&difficulty=Medium,Hard&sortBy=submissions
//same as LeetCode ques - https://leetcode.com/problems/palindrome-linked-list/description/

// Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

// Examples:

// Input: LinkedList: 1->2->1->1->2->1
// Output: true
// Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

// Input: LinkedList: 1->2->3->4
// Output: false
// Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1) 
// Note: You should not use the recursive stack space as well

// Constraints:
// 1 <= number of nodes <= 105
// 1 ≤ node->data ≤ 103


//find the centre of the link then reverse the elements after that then compare the elements from starting and from centre if they are equal till last means correct

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Find the middle element from the slow fast approach. Then reverse the list after the middle element. Now compare the reversed part and the inital part 
// for checking palindrome. This is how I did it. We just have to make one change in this i.e reverse back the LL to original form and use rerverse func for
//modular approach

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
      
        Node*slow=head,*fast=head;
        while(fast->next&&fast->next->next)
        {
          slow=slow->next;
          fast=fast->next->next;
        }
        Node*prev=NULL,*curr=slow->next,*nnode=NULL;
        while(curr)
        {
            nnode=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nnode;
        }
        curr=head;
        while(curr&&prev)
        {
            if(curr->data==prev->data)
            {
                curr=curr->next;
                prev=prev->next;
                continue;
            }
            else return false;
        }
        return true;
    }
};


  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  // brute force appraoch get a stack and add elements into it. Compare the stack with LL then  give result accordingly.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp=head;
        while(temp)
        {
           st.push(temp->val);
           temp=temp->next;

        }
        temp=head;
        while(temp)
        {
            if(st.top()!=temp->val) return false;
            else
            {
            st.pop();
            temp=temp->next;
            } 
                
        }
        return true;
        
    }
};

//Optimised solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Reverse(ListNode* head)
    {
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
    bool isPalindrome(ListNode* head) {
   
        ListNode* temp=head,* slow=head,* fast=head,*p,*RevHead;
        while(fast->next&&fast->next->next)
        {
           slow=slow->next;
           fast=fast->next->next;
        }

        RevHead=Reverse(slow->next);
        p=head;
        temp=RevHead;
        while(temp)
        {
          if(temp->val!=p->val)
          {
            Reverse(RevHead);
            return false;
          } 
          temp=temp->next;
          p=p->next; 
                
        }
        return true;
        
    }
};

