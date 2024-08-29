//9 Aug LL session ques 5
//https://www.geeksforgeeks.org/problems/reorder-list/1?page=3&category=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
  public:
    // void reorderList(Node* head) {
    //     // Your code here
    //     Node*p=head,*temp;
    //     int i=0,j;
    //     while(p)
    //     {
    //         i++;
    //         p=p->next;
    //     }
    //     p=head;
    //     if(i%2==0) j=1;
    //     else j=0;
    //     while(j< i/2)
    //     {
    //         p=p->next;
    //         j++;
    //     }
    //     Node*curr=p->next,*nnode=NULL,*prev=NULL;
    //     while(curr)
    //     {
    //         nnode=curr->next;
    //         curr->next=prev;
            
    //         prev=curr;
    //         curr=nnode;
            
    //     }
    //     p=prev;
    //     temp=head;
    //     while(p)
    //     {
    //         curr=temp->next;
    //         nnode=p->next;
    
    //         temp->next=p;
    //         p->next=curr;
    //         p=nnode;
    //     }
        
        
    // }
    void reorderList(Node* head) {
    if (!head || !head->next) return; // Handle edge cases (empty list or single node)
    
    // Step 1: Find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse the second half of the list
    Node* prev = NULL;
    Node* curr = slow->next;
    slow->next = NULL; // Break the list into two halves
    while (curr) {
        Node* nnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nnode;
    }
    
    // Step 3: Merge the two halves
    Node* first = head;
    Node* second = prev;
    while (second) {
        Node* temp1 = first->next;
        Node* temp2 = second->next;
        
        first->next = second;
        second->next = temp1;
        
        first = temp1;
        second = temp2;
    }
}

};

