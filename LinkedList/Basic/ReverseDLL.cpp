//link - https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

// Reverse a Doubly Linked List
// Difficulty: EasyAccuracy: 70.38%Submissions: 123K+Points: 2
// Given a doubly linked list of n elements. Your task is to reverse the doubly linked list in-place.

// Example 1:

// Input:
// LinkedList: 3 <--> 4 <--> 5
// Output: 5 4 3
// Example 2:

// Input:
// LinkedList: 75 <--> 122 <--> 59 <--> 196
// Output: 196 59 122 75
// Your Task:
// Your task is to complete the given function reverseDLL(), which takes head reference as argument and this function should reverse the elements such that the tail becomes the new head and all pointers are pointing in the right order. You need to return the new head of the reversed list. The printing and verification is done by the driver code.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= number of nodes <= 104
// 0 <= value of nodes <= 104

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }    
};

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node*low=head;
        Node*high=head;
        while(high->next)
        {
            high=high->next;
        }
       while(low<high)
       {
           swap(low->data,high->data);
           low=low->next;
           high=high->prev;
       }
       return head; 
    }
};

//second method by link swapping

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        
      Node *p=head;
      while(p)
      {
          swap(p->next,p->prev);
          if(p->prev==NULL) 
          {head=p; break;}
          p=p->prev;
      }
      
       return head;
       
    }
};

