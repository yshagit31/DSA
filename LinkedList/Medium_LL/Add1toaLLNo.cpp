////9 Aug LL session ques 9
//https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?page=1&category=Linked%20List&sortBy=submissions

//Add 1 to a Linked List Number

// You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

// Note: The head represents the first element of the given array.

// Examples :

// Input: LinkedList: 4->5->6
// Output: 457

// Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
// Input: LinkedList: 1->2->3
// Output: 124
 
// Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= len(list) <= 105
// 0 <= list[i] <= 105

//{ Driver Code Starts
// Initial template for C++

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
// Reverse the last, then add 1 by taking a carry variable then keep adding. If carry is >0 at last add one more node and update head;
class Solution {
  public:
    Node* addOne(Node* head) {
        Node*curr=head,*prev=NULL,*nnode=NULL,*last;
        while(curr)
        {
            nnode=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nnode;
        }
        head=prev;
        int carry=1,sum=0;
        while(prev)
        {
            sum=prev->data+carry;
            if(sum>=10)
            {
                prev->data=sum%10;
                carry=1;
            }
            else 
            { 
                prev->data=sum;
                carry=0;
            }
            last=prev;
            prev=prev->next;
        }
        if(carry>0)
        {
            Node* temp=new Node(carry);
            last->next=temp;
        }
        
        curr=head,prev=NULL,nnode=NULL;
        while(curr)
        {
            nnode=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nnode;
        }
        head=prev;
        
        return head;
    }
};


//Same appraoch just Reverse is done bya func


class Solution {
  public:
  Node* Reverse(Node* head)
  {
      Node*curr=head,*prev=NULL,*nnode=NULL;
      while(curr)
      {
          nnode=curr->next;
          curr->next=prev;
          
          prev=curr;
          curr=nnode;
      }
      return prev;
  }
    Node* addOne(Node* head) {
       
        Node*prev=NULL,*last;
        head=Reverse(head);
        
        prev=head;
        int carry=1,sum=0;
        
        while(prev)
        {
            sum=prev->data+carry;
            if(sum>=10)
            {
                prev->data=sum%10;
                carry=1;
            }
            else 
            { 
                prev->data=sum;
                carry=0;
            }
            last=prev;
            prev=prev->next;
        }
        
        if(carry>0)
        {
            Node* temp=new Node(carry);
            last->next=temp;
        }
        
        head=Reverse(head);
  
        
        return head;
    }
};

// Recursive approach