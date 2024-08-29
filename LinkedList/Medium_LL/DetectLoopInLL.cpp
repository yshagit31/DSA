//9 Aug LL session ques 2
//https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1?page=1&category=Linked%20List&sortBy=submissions

// Given the head of a singly linked list, the task is to check if the linked list has a loop. A loop means that the last node of the linked list is connected back to a node in the same list.  So if the next of the last node is null. then there is no loop. We need to return true if there is a loop, otherwise false.

// The following is an internal representation of every test case (three inputs).
// A LinkedList and a pos (1-based index)-Position of the node to which the last node links back if there is a loop. If the linked list does not have any loop, then pos = 0.

// Examples:

// Input: LinkedList: 1->3->4, pos = 2
// Output: true
// Explanation: 

// See the above list there exists a loop connecting the last node back to the second node.
// Input: LinkedList: 1->8->3->4, pos = 0
// Output: false
// Explanation: 

// There is no loop exists.
// Input: LinkedList: 1->2->3->4, pos = 1
// Output: true
// Explanation:

// A loop is present connecting the last node back to the first node.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ number of nodes ≤ 104
// 1 ≤ node->data ≤ 103


//my method store the values in a hashmap and if the frequency of a certain address is >1 then means the element is again being gone to

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
  public:
    bool detectLoop(Node* head) {
        unordered_map<Node*,int> hashmap;
        Node*p=head;
        while(p)
        {
          hashmap[p]++;
          if(hashmap[p]>1)
          {
              return true;
          }
          p=p->next;
        }
        return false;
    }
};

//hashmap method of striver

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*temp=head;
        unordered_map<ListNode*,int> hashmap;
        while(temp)
        {
            if(hashmap.find(temp)!=hashmap.end())
            {
                return true;
            }
            hashmap[temp]++;
            temp=temp->next;
        }
        return false;
        
    }
};

//Optimal approach tortoise and hare method or as we say it Floyds cycle finding algo
// we check if fast is null or its next is null coz we can be at last or second last node acc to odd or even LL

 bool hasCycle(ListNode *head) {
        ListNode*slow=head,*fast=head;
      
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
        
    }