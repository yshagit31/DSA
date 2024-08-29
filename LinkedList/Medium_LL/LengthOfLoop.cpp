//https://www.geeksforgeeks.org/problems/find-length-of-loop/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-length-of-loop
// Find length of Loop

// Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

// Examples:

// Note: 'c' is the position of the node to which the last node is connected. If c is 0, then there is no loop.

// Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
// Output: 7
// Explanation: The loop is 45->33. So length of loop is 33->10->21->39-> 90->58->45 = 7. The number 33 is connected to the last node to form the loop because according to the input the 4th node from the beginning(1 basedindex) will be connected to the last node for the loop.
 
// Input: LinkedList: 1-> 0, c = 2
// Output: 0
// Explanation: The length of the loop is 2.

// Input: LinkedList: 5-> 4, c = 0
// Output: 0
// Explanation: There is no loop.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= no. of nodes <= 106
// 0 <= node->data <=106
// 0 <= c<= n-1


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

//Brute force approach. Store the LL count and the node in a map, if the node is visited again. The no of LL will be intial count at that node - count at that moment

class Solution {
  public:
  
    int countNodesinLoop(struct Node *head) 
    {
        Node*temp=head;
        int t=1;
        unordered_map<Node*,int> hashmap;
        while(temp)
        {
            if(hashmap.find(temp)!=hashmap.end())
            {
             return t-hashmap[temp];   
            }
            hashmap[temp]=t;
            t++;
            temp=temp->next;
        }
        return 0;
    }
};

//Tortoise and hare method, when the pointers are equal we can then count node till we get the node same again

class Solution {
  public:
  int LoopLength(Node*slow,Node*fast)
  {
      int cnt=1;
      fast=fast->next;
      while(slow!=fast)
      {
          fast=fast->next;
          cnt++;
      }
      return cnt;
  }
  
    int countNodesinLoop(struct Node *head) 
    {
        Node*slow=head,*fast=head;
       
        int t1=1,t2=1;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

             if(fast==slow)
            {
                return LoopLength(slow,fast);
            }
        }
        return 0;
    }
};
