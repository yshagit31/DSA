// link - https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=given-a-linked-list-of-0s-1s-and-2s-sort-it
// Sort a linked list of 0s, 1s and 2s
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Example 1:

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated
// to the left end of the linked list,
// 2s to the right end of the list, and
// 1s in between.
// Example 2:

// Input:
// N = 4
// value[] = {2,2,0,1}
// Output: 0 1 2 2
// Explanation: After arranging all the
// 0s,1s and 2s in the given format,
// the output will be 0 1 2 2.
// Your Task:
// The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 106

// first approach is brute force we can count no of o's , 1's and 2's and then fill the ll accordingly;

// The approach 2nd is to take three dummy nodes and three pointers to them. Now we traverse the list and on encountering zero we add the link to the
//  first node and on encountering One we add the link to the second node and one encountering Two we add it to third node.
//  Now we keep adding till at last. After than we join Dummy Node of zero pointer to Dummy Node of 1 if  it exits otherwise to 2.
//  And Dummy Node of 1  pointer to Dummy Node of 2. And Dummy Node of two pointer to NULL.
//  Now update the head and return it.

#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        Node *HeadOne = new Node(-1);
        Node *HeadTwo = new Node(-1);
        Node *HeadZero = new Node(-1);

        Node *Zero = HeadZero, *One = HeadOne, *Two = HeadTwo, *p = head;

        while (p)
        {
            if (p->data == 0)
            {
                Zero->next = p;
                Zero = p;
            }
            else if (p->data == 1)
            {
                One->next = p;
                One = p;
            }
            else if (p->data == 2)
            {
                Two->next = p;
                Two = p;
            }

            p = p->next;
        }

        Zero->next = HeadOne->next ? HeadOne->next : HeadTwo->next;
        One->next = HeadTwo->next;
        Two->next = NULL;

         delete(HeadZero);
         delete(HeadOne);
         delete(HeadTwo);

        head = HeadZero->next;
        return head;
    }
};
