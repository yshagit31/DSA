//9 Aug LL session ques 1
//https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?page=1&category=Linked%20List&sortBy=submissions
//same as LeetCode ques
//https://leetcode.com/problems/intersection-of-two-linked-lists/

// Given two singly linked lists, return the point where two linked lists intersect.

// Note: If the linked lists do not merge at any point, return -1.

// Examples:

// Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4
 
// Output: 4
// Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.

// Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5
 
// Output: 8
// Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
// Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
// Output: -1
// Explanation: There is no common part, so there is no interaction point.
// Expected Time Complexity: O(n+m)
// Expected Space Complexity: O(1)

// Constraints:
// 2 ≤ size of first linkedist + size of second linkedlist ≤ 2*105
// -1000 ≤ data of nodes ≤ 1000


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

// Optimised approach
//In this approach we traverse the linked list until we find null on getting null we take the pointer to the head of the other linked list so since ll are of 
//uneven length first the smaller ll pointer will go to larger ll head then the other ll pointer will go to other head acc to the length diff bw ll and the first 
//pointer will have traversed the diff bw the ll in that time and now the two ponter will be at the same diff from the intersection node and they will meet

class Solution {
  public:
    int intersectPoint(Node* head1, Node* head2) {
    
        Node*p1=head1;
        Node*p2=head2;
        while(p1!=p2)
        {
            if(p1==NULL)
            {
                p1=head2;
            }
            if(p2==NULL)
            {
                p2=head1;
            }
            p2=p2->next;
            p1=p1->next;
        }
            if(p1==p2) return p1->data;
        return -1;
    }
};

//brute force take a hashmap store the nodes in it if the visited node is visited again that is intersection point
// I did in one traversal stiver gave a method to first read all the values of a LL and then read the values again of other one
//if we encounter a previously existing node that is the intersection

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
      
        Node*p1=head1;
        Node*p2=head2;
        unordered_map <Node*,int> hashmap;
        
        while(p1||p2)
        {
            if(p1) hashmap[p1]++;
            if(p2) hashmap[p2]++;
            if(hashmap[p1]>1) return p1->data;
            if(hashmap[p2]>1) return p2->data;
            
            p2=p2->next;
            p1=p1->next;
        }
            
        return -1;
    }
};

//or what we can do is find the diff be length of ll and move the longer ll to the diff and now the ll pointers will be at equal distance from the intersection
//now we can easily traverse in one loop and get it

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    int GetLength(ListNode*p)
    {
        int i=0;
        while(p)
        {
            i++;
            p=p->next;
         }
         return i;

    }
    ListNode* GetCollision(ListNode* p1,ListNode* p2,int n)
    {
        while(n)
        {
            n--;
            p1=p1->next;
        }
        while(p1!=p2)
        {
            p1=p1->next;
            p2=p2->next;
        }
        return p1;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1,n2;
        n1=GetLength(headA);
        n2=GetLength(headB);

        if(n1>n2)
        {
            return GetCollision(headA,headB,n1-n2);
        }
        else 
        {
            return GetCollision(headB,headA,n2-n1);
        }
 
    }
};

//my method of length

    int intersectPoint(Node* head1, Node* head2) {
      
        Node*p1=head1;
        Node*p2=head2;
        int i=0,j=0,k;
        
        while(p1)
        {
           i++;
            p1=p1->next;
        }
         while(p2)
        {
           j++;
            p2=p2->next;
        }
        k=i>j? i-j:j-i;
        
        p1=head1;
        p2=head2;
        
        if(i>j)
        {
           while(k)
           {
               k--;
               p1=p1->next;
           }
        }
        else if(i<j)
        {
           while(k)
           {
              k--;
               p2=p2->next;
           }
        }
      
        while(p1!=p2)
        {
            
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==p2) return p1->data;
        return -1;
    }

   //Modular approach by functions
  class Solution {
  public:
    int getLength(Node*head)
    {
        int len=0;
        Node*p=head;
         while(p)
        {
           len++;
            p=p->next;
        }
        return len;
    }
    Node *Move(Node*temp,int k)
    {
        while(k)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }
    int intersectPoint(Node* head1, Node* head2) {
      
        Node*p1=head1;
        Node*p2=head2;
        int i=0,j=0,k;
        
        i=getLength(head1);
        j=getLength(head2);
        
        k=i>j? i-j:j-i;
        
        p1=head1;
        p2=head2;
        
        if(i>j)
        {
          p1=Move(p1,k);
        }
        else if(i<j)
        {
          p2=Move(p2,k);
        }
      
        while(p1!=p2)
        { 
            p1=p1->next;
            p2=p2->next;
        }
        if(p1==p2) return p1->data;
        return -1;
    }
};